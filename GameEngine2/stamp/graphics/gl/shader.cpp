#include <stamp/graphics/gl/shader.h>
#include <functional>
#include <sstream>
#include <stamp/debug.h>

using namespace STAMP_GRAPHICS_GL_NAMESPACE;

std::string shader_type::to_definestring(shader_type_t type) {
	switch (type) {
	case VertexShader: return "VERTEX_SHADER";
	case TessControlShader: return "TESS_CONTROL_SHADER";
	case TessEvaluationShader: return "TESS_EVALUATION_SHADER";
	case GeometryShader: return "GEOMETRY_SHADER";
	case FragmentShader: return "FRAGMENT_SHADER";
	case ComputeShader: return "COMPUTE_SHADER";
	}
	return "";
}

GLenum shader_type::to_glenum(shader_type_t type) {
	switch (type) {
	case VertexShader: return GL_VERTEX_SHADER;
	case TessControlShader: return GL_TESS_CONTROL_SHADER;
	case TessEvaluationShader: return GL_TESS_EVALUATION_SHADER;
	case GeometryShader: return GL_GEOMETRY_SHADER;
	case FragmentShader: return GL_FRAGMENT_SHADER;
	case ComputeShader: return GL_COMPUTE_SHADER;
	}
	return 0;
}

bool ParseCStyle(std::istream& in, std::ostream& out, const std::function<std::unique_ptr<std::istream>(std::string_view)>& headers) {
	std::string l;
	int linen = 0;
	while (in) {
		std::getline(in, l);
		linen++;

		if (l.starts_with("#include")) {
			auto s = l.find_first_of('<', sizeof("#include"));
			auto e = l.find_last_of('>');
			STAMPASSERT(s != std::string::npos && e != std::string::npos && e != s, "stamp::graphics::shader - failed to parse shader. invalid #include statement");

			std::string name = l.substr(s + 1, e - (s + 1));
			auto headerStream = headers(name);
			STAMPASSERT((bool)headerStream, "stamp::graphics::shader - failed to parse shader. unable to find include file: " << name);

			if (!ParseCStyle(*headerStream.get(), out, headers)) {
				return false;
			}
			out << "#line " << linen << std::endl;
		}
		else {
			out << l << std::endl;
		}
	}
}

GLenum IShaderProgram::CompileShader(std::string& version, std::string& progTxt, shader_type_t type) {
	GLint compiled = 0;
	GLsizei log_length = 0;
	GLuint comp = glCreateShader(shader_type::to_glenum(type));
	std::string p = version + std::string("#define ") + shader_type::to_definestring(type) + "\n#line 2" + progTxt;

	const char* c = p.c_str();
	glShaderSource(comp, 1, &c, 0);

	glCompileShader(comp);
	glGetShaderiv(comp, GL_COMPILE_STATUS, &compiled);
	if (compiled != GL_TRUE) {
		std::string message(4096, '\0');
		glGetProgramInfoLog(program, message.size(), &log_length, message.data());
		STAMPSTACK();
		STAMPDMSG("stamp::graphics::gl::ShaderProgramBase::set - compilation error" << std::endl << message); //add line number string
	}
	return comp;
}

void IShaderProgram::Compile(std::istream& prog, shader_type_t type, const std::vector<std::string>& defines) {
	if (program) glDeleteProgram(program);
	program = glCreateProgram();
	//reseve size of strings?
	std::string version{};
	std::stringstream str{};
	
	std::getline(prog, version);
	ParseCStyle(prog, str, [&defines](std::string_view str) -> std::unique_ptr<std::istream> {
		if (str == "stampdefaults") {
			std::stringstream s{};
			for (const auto& def : defines) {
				s << "#define " << def << std::endl;
			}
			for (const auto& def : default_defines) {
				s << "#define " << def << std::endl;
			}
			return std::make_unique<std::stringstream>(std::move(s));
		}
		return std::make_unique<std::stringstream>();
	});
	std::string progTxt = str.str();

	GLint compiled = 0;
	GLsizei log_length = 0;
	std::vector<GLuint> shaderComp{};
	if (type & shader_type::VertexShader) {
		GLenum comp = CompileShader(version, progTxt, shader_type::VertexShader);
		shaderComp.push_back(comp);
		glAttachShader(program, comp);
	}
	if (type & shader_type::TessControlShader) {
		GLenum comp = CompileShader(version, progTxt, shader_type::TessControlShader);
		shaderComp.push_back(comp);
		glAttachShader(program, comp);
	}
	if (type & shader_type::TessEvaluationShader) {
		GLenum comp = CompileShader(version, progTxt, shader_type::TessEvaluationShader);
		shaderComp.push_back(comp);
		glAttachShader(program, comp);
	}
	if (type & shader_type::GeometryShader) {
		GLenum comp = CompileShader(version, progTxt, shader_type::GeometryShader);
		shaderComp.push_back(comp);
		glAttachShader(program, comp);
	}
	if (type & shader_type::FragmentShader) {
		GLenum comp = CompileShader(version, progTxt, shader_type::FragmentShader);
		shaderComp.push_back(comp);
		glAttachShader(program, comp);
	}
	if (type & shader_type::ComputeShader) {
		GLenum comp = CompileShader(version, progTxt, shader_type::ComputeShader);
		shaderComp.push_back(comp);
		glAttachShader(program, comp);
	}
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &compiled);
	if (compiled != GL_TRUE) {
		std::string message(4096, '\0');
		glGetProgramInfoLog(program, message.size(), &log_length, message.data());
		STAMPSTACK();
		STAMPDMSG("stamp::graphics::gl::ShaderProgramBase::setShader::set - compilation error");
		STAMPDMSG(message);
	}
	for (int i = 0; i < shaderComp.size(); i++) {
		glDeleteShader(shaderComp[i]);
	}
}

IShaderProgram::IShaderProgram(IShaderProgram&& other) noexcept {
	program = other.program;
	other.program = 0;
}

IShaderProgram& IShaderProgram::operator =(IShaderProgram&& other) noexcept {
	using std::swap;
	swap(program, other.program);

	return *this;
}
IShaderProgram::~IShaderProgram() {
	if (!program) return;
	glDeleteProgram(program);
	program = 0;
}

int IShaderProgram::InternalProgram() const {
	return program;
}
void IShaderProgram::Bind() const {
	if (currentProgram == program) return;
	glUseProgram(program);
	currentProgram = program;
}
bool IShaderProgram::IsValid() const {
	return program != 0;
}

void IShaderProgram::Uniform(GLint location, const Texture& texture) {
	glProgramUniform1i(program, location, (GLint)texture.Binding());
}
void IShaderProgram::Uniform(GLint location, int value) {
	glProgramUniform1i(program, location, value);
}
void IShaderProgram::Uniform(GLint location, unsigned int value) {
	glProgramUniform1ui(program, location, value);
}
void IShaderProgram::Uniform(GLint location, float value) {
	glProgramUniform1f(program, location, value);
}
void IShaderProgram::Uniform(GLint location, double value) {
	glProgramUniform1d(program, location, value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2i& value) {
	glProgramUniform2iv(program, location, 1, (const int*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2ui& value) {
	glProgramUniform2uiv(program, location, 1, (const unsigned int*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2f& value) {
	glProgramUniform2fv(program, location, 1, (const float*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2d& value) {
	glProgramUniform2dv(program, location, 1, (const double*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3i& value) {
	glProgramUniform3iv(program, location, 1, (const int*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3ui& value) {
	glProgramUniform3uiv(program, location, 1, (const unsigned int*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3f& value) {
	glProgramUniform3fv(program, location, 1, (const float*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3d& value) {
	glProgramUniform3dv(program, location, 1, (const double*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4i& value) {
	glProgramUniform4iv(program, location, 1, (const int*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4ui& value) {
	glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4f& value) {
	glProgramUniform4fv(program, location, 1, (const float*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4d& value) {
	glProgramUniform4dv(program, location, 1, (const double*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix3f& value) {
	glProgramUniformMatrix3fv(program, location, 1, false, (const float*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix3d& value) {
	glProgramUniformMatrix3dv(program, location, 1, false, (const double*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix4f& value) {
	glProgramUniformMatrix4fv(program, location, 1, false, (const float*)value);
}
void IShaderProgram::Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix4d& value) {
	glProgramUniformMatrix4dv(program, location, 1, false, (const double*)value);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<int> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<int> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform1fv(program, location, end - begin, (const int*)(&*begin));
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<unsigned int> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<unsigned int> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform1fv(program, location, end - begin, (const unsigned int*)(&*begin));
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<float> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<float> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform1fv(program, location, end - begin, (const float*)(&*begin));
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<double> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<double> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform1dv(program, location, end - begin, (const double*)(&*begin));
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2i> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2i> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform2iv(program, location, end - begin, (const int*)(&*begin));
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2ui> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2ui> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform2uiv(program, location, end - begin, (const unsigned int*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform2fv(program, location, end - begin, (const float*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform2dv(program, location, end - begin, (const double*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3i> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3i> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform3iv(program, location, end - begin, (const int*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3ui> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3ui> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform3uiv(program, location, end - begin, (const unsigned int*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform3fv(program, location, end - begin, (const float*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform3dv(program, location, end - begin, (const double*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4i> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4i> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform4iv(program, location, end - begin, (const int*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4ui> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4ui> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform4iv(program, location, end - begin, (const unsigned int*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform4iv(program, location, end - begin, (const float*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniform4iv(program, location, end - begin, (const double*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniformMatrix3fv(program, location, end - begin, false, (const float*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniformMatrix3dv(program, location, end - begin, false, (const double*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4f> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniformMatrix4fv(program, location, end - begin, false, (const float*)begin);
}

template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	std::vector<std::iter_value_t<Iter>> vector{};
	for (auto it = begin; it != end; it++) vector.push_back(*it);
	Uniform(location, std::begin(vector), std::end(vector));
}
template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4d> Iter>
void IShaderProgram::Uniform(GLint location, Iter begin, Iter end) {
	glProgramUniformMatrix4dv(program, location, end - begin, false, (const double*)begin);
}

void IShaderProgram::UniformBuffer(GLint location, int index) const {
	glUniformBlockBinding(program, location, index);
}
void IShaderProgram::ShaderStorageBuffer(GLint location, int index) const {
	glShaderStorageBlockBinding(program, location, index);
}
GLint IShaderProgram::GetUniformLocation(const char* name) const {
	return glGetUniformLocation(program, name);
}
GLint IShaderProgram::GetUniformBufferLocation(const char* name) const {
	return glGetUniformBlockIndex(program, name);
}
GLint IShaderProgram::GetUniformIndex(const char* name) const {
	return glGetProgramResourceIndex(program, GL_UNIFORM, name);
}
GLint IShaderProgram::GetUniformBufferIndex(const char* name) const {
	return glGetProgramResourceIndex(program, GL_UNIFORM_BLOCK, name);
}
GLint IShaderProgram::GetShaderStorageBufferIndex(const char* name) const {
	return glGetProgramResourceIndex(program, GL_SHADER_STORAGE_BLOCK, name);
}

std::shared_ptr<RenderShaderProgram> RenderShaderProgram::ParseStream_glsl(std::istream& prog, shader_type_t type, const std::vector<std::string>& defines) {
	auto r = std::make_shared<RenderShaderProgram>();
	r->Compile(prog, shader_type::VertexShader | shader_type::FragmentShader | type, defines);
	return r;
}

std::shared_ptr<ComputerShaderProgram> ComputerShaderProgram::ParseStream_glsl(std::istream& prog, const std::vector<std::string>& defines) {
	auto r = std::make_shared<ComputerShaderProgram>();
	r->Compile(prog, shader_type::ComputeShader, defines);
	return r;
}
void ComputerShaderProgram::Dispatch(int groupsX, int groupsY, int groupsZ) {
	Bind();
	glDispatchCompute(groupsX, groupsY, groupsZ);
}
int ComputerShaderProgram::MaxDispatchInvocations() {
	static int n = []() {
		int k;
		glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &k);
		return k;
	}();
	return n;
}
int ComputerShaderProgram::MaxDispatchPerGroup() {
	static int n = []() {
		int k;
		glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_COUNT, &k);
		return k;
		}();
	return n;
}