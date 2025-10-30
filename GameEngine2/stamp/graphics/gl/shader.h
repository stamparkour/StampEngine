//stamp/graphics/gl/shader.h

#pragma once
#ifndef STAMP_GRAPHICS_GL_SHADER_H
#define STAMP_GRAPHICS_GL_SHADER_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <stamp/graphics/gl/define.h>
#include <string>
#include <stamp/memory.h>
#include <stamp/math/vector.h>
#include <stamp/math/vector.h>

STAMP_GRAPHICS_GL_NAMESPACE_BEGIN

using shader_type_t = size_t;
namespace shader_type {
	enum : shader_type_t {
		VertexShader = 1,
		TessControlShader = 2,
		TessEvaluationShader = 4,
		GeometryShader = 8,
		FragmentShader = 16,
		ComputeShader = 32,
	};

	std::string to_definestring(shader_type_t type) {
		switch(type) {
		case VertexShader: return "VERTEX_SHADER";
		case TessControlShader: return "TESS_CONTROL_SHADER";
		case TessEvaluationShader: return "TESS_EVALUATION_SHADER";
		case GeometryShader: return "GEOMETRY_SHADER";
		case FragmentShader: return "FRAGMENT_SHADER";
		case ComputeShader: return "COMPUTE_SHADER";
		}
		return "";
	}
	GLenum to_glenum(shader_type_t type) {
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
};

class ShaderProgramBase : public STAMP_NAMESPACE::enable_threadsafe_from_this<class ShaderProgramBase> {
private:
	GLuint program = 0;
	static inline thread_local GLuint currentProgram = 0;

	GLenum ToShaderComp(std::string& version, std::string& progTxt, shader_type_t type) {
		static GLint compiled = 0;
		static GLchar message[1024]{};
		static GLsizei log_length = 0;
		GLuint comp = glCreateShader(shader_type::to_glenum(type));
		std::string p = version + std::string("#define ") + shader_type::to_definestring(type) + "\n" + progTxt;

		const char* c = p.c_str();
		glShaderSource(comp, 1, &c, 0);

		glCompileShader(comp);
		glGetShaderiv(comp, GL_COMPILE_STATUS, &compiled);
		if (compiled != GL_TRUE) {
			glGetShaderInfoLog(comp, sizeof(message), &log_length, message);
			STAMPSTACK();
			STAMPDMSG("render::ShaderProgramBase::set - compilation error" << std::endl << message << std::endl << ToLineNumberString(p));
		}
		return comp;
	}
protected:
	ShaderProgramBase() {}
	void set(std::istream& prog, ShaderType type, const std::vector<std::string>& defines = {}) {
		if (program) glDeleteProgram(program);
		program = glCreateProgram();
		//reseve size of strings?
		std::string version{};
		version.reserve(32);
		std::string progTxt{};
		progTxt.reserve(4096);
		while ((bool)prog) {//get version
			char c = prog.get();
			if (c == '\r') continue;
			version += c;
			if (c == '\n') break;
		}
		while ((bool)prog) {//get text
			char c = prog.get();
			if (c == '\r' || c == -1) continue;
			progTxt += c;
		}
		for (int i = 0; i < defines.size(); i++) {
			progTxt = std::string("#define ") + defines[i] + "\n" + progTxt;
		}
		static GLint compiled = 0;
		static GLchar message[1024]{};
		static GLsizei log_length = 0;
		std::vector<GLuint> shaderComp{};
		if (type._value & ShaderType::VertexShader) {
			GLenum comp = ToShaderComp(version, progTxt, 0);
			shaderComp.push_back(comp);
			glAttachShader(program, comp);
		}
		if (type._value & ShaderType::TessControlShader) {
			GLenum comp = ToShaderComp(version, progTxt, 1);
			shaderComp.push_back(comp);
			glAttachShader(program, comp);
		}
		if (type._value & ShaderType::TessEvaluationShader) {
			GLenum comp = ToShaderComp(version, progTxt, 2);
			shaderComp.push_back(comp);
			glAttachShader(program, comp);
		}
		if (type._value & ShaderType::GeometryShader) {
			GLenum comp = ToShaderComp(version, progTxt, 3);
			shaderComp.push_back(comp);
			glAttachShader(program, comp);
		}
		if (type._value & ShaderType::FragmentShader) {
			GLenum comp = ToShaderComp(version, progTxt, 4);
			shaderComp.push_back(comp);
			glAttachShader(program, comp);
		}
		if (type._value & ShaderType::ComputeShader) {
			GLenum comp = ToShaderComp(version, progTxt, 5);
			shaderComp.push_back(comp);
			glAttachShader(program, comp);
		}
		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &compiled);
		if (compiled != GL_TRUE) {
			glGetProgramInfoLog(program, 1024, &log_length, message);
			STAMPSTACK();
			STAMPDMSG("render::ShaderProgramBase::setShader::set - compilation error");
			STAMPDMSG(message);
		}
		for (int i = 0; i < shaderComp.size(); i++) {
			glDeleteShader(shaderComp[i]);
		}
	}
public:
	ShaderProgramBase(const ShaderProgramBase& other) = delete;
	ShaderProgramBase(ShaderProgramBase&& other) noexcept {
		using std::swap;
		swap(*this, other);
	}
	ShaderProgramBase& operator =(const ShaderProgramBase& other) = delete;
	ShaderProgramBase& operator =(ShaderProgramBase&& other) noexcept {
		using std::swap;
		swap(*this, other);
		return *this;
	}
	inline friend void swap(ShaderProgramBase& a, ShaderProgramBase& b) noexcept {
		using std::swap;
		swap(a.program, b.program);
	}
	virtual ~ShaderProgramBase() {
		if (program) glDeleteProgram(program);
		program = 0;
	}
	int ProgramID() {
		return program;
	}
	void Bind() {
		if (currentProgram == program) return;
		glUseProgram(program);
		currentProgram = program;
	}
	bool isValid() const {
		return program != 0;
	}
	void Uniform(GLint location, const SamplerBase* value) {
		STAMPDMSG("render::ShaderProgramBase::Uniform - function not implemented");
		//STAMPERROR(!value->isActive(), "render::ShaderProgramBase::uniform - texture is not active");
		glProgramUniform1i(program, location, value->GetActiveTextureIndex());
		std::cout << "render::ShaderProgramBase::uniformD - index: " << value->GetActiveTextureIndex() << " loc: " << location << " prog: " << program << std::endl;
		GLSTAMPERROR;
	}
	void Uniform(GLint location, int value) {
		glProgramUniform1i(program, location, value);
	}
	void Uniform(GLint location, unsigned int value) {
		glProgramUniform1ui(program, location, value);
	}
	void Uniform(GLint location, float value) {
		glProgramUniform1f(program, location, value);
	}
	void Uniform(GLint location, double value) {
		glProgramUniform1d(program, location, value);
	}
	void Uniform(GLint location, const math::Vec2i& value) {
		glProgramUniform2iv(program, location, 1, (const int*)value);
	}
	void Uniform(GLint location, const math::Vec2ui& value) {
		glProgramUniform2uiv(program, location, 1, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Vec2f& value) {
		glProgramUniform2fv(program, location, 1, (const float*)value);
	}
	void Uniform(GLint location, const math::Vec2d& value) {
		glProgramUniform2dv(program, location, 1, (const double*)value);
	}
	void Uniform(GLint location, const math::Vec3i& value) {
		glProgramUniform3iv(program, location, 1, (const int*)value);
	}
	void Uniform(GLint location, const math::Vec3ui& value) {
		glProgramUniform3uiv(program, location, 1, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Vec3f& value) {
		glProgramUniform3fv(program, location, 1, (const float*)value);
	}
	void Uniform(GLint location, const math::Vec3d& value) {
		glProgramUniform3dv(program, location, 1, (const double*)value);
	}
	void Uniform(GLint location, const math::Vec4i& value) {
		glProgramUniform4iv(program, location, 1, (const int*)value);
	}
	void Uniform(GLint location, const math::Vec4ui& value) {
		glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Vec4f& value) {
		glProgramUniform4fv(program, location, 1, (const float*)value);
	}
	void Uniform(GLint location, const math::Vec4d& value) {
		glProgramUniform4dv(program, location, 1, (const double*)value);
	}
	void Uniform(GLint location, const math::Quati& value) {
		glProgramUniform4iv(program, location, 1, (const int*)value);
	}
	void Uniform(GLint location, const math::Quatui& value) {
		glProgramUniform4uiv(program, location, 1, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Quatf& value) {
		glProgramUniform4fv(program, location, 1, (const float*)value);
	}
	void Uniform(GLint location, const math::Quatd& value) {
		glProgramUniform4dv(program, location, 1, (const double*)value);
	}
	void Uniform(GLint location, const math::Mat4f& value) {
		glProgramUniformMatrix4fv(program, location, 1, false, (const float*)value);
	}
	void Uniform(GLint location, const math::Mat4d& value) {
		glProgramUniformMatrix4dv(program, location, 1, false, (const double*)value);
	}
	void Uniform(GLint location, const int* value, GLsizei count) {
		glProgramUniform1iv(program, location, count, value);
	}
	void Uniform(GLint location, const unsigned int* value, int count) {
		glProgramUniform1uiv(program, location, count, value);
	}
	void Uniform(GLint location, const float* value, int count) {
		glProgramUniform1fv(program, location, count, value);
	}
	void Uniform(GLint location, const double* value, int count) {
		glProgramUniform1dv(program, location, count, value);
	}
	void Uniform(GLint location, const math::Vec2i* value, int count) {
		glProgramUniform2iv(program, location, count, (const int*)value);
	}
	void Uniform(GLint location, const math::Vec2ui* value, int count) {
		glProgramUniform2uiv(program, location, count, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Vec2f* value, int count) {
		glProgramUniform2fv(program, location, count, (const float*)value);
	}
	void Uniform(GLint location, const math::Vec2d* value, int count) {
		glProgramUniform2dv(program, location, count, (const double*)value);
	}
	void Uniform(GLint location, const math::Vec3i* value, int count) {
		glProgramUniform3iv(program, location, count, (const int*)value);
	}
	void Uniform(GLint location, const math::Vec3ui* value, int count) {
		glProgramUniform3uiv(program, location, count, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Vec3f* value, int count) {
		glProgramUniform3fv(program, location, count, (const float*)value);
	}
	void Uniform(GLint location, const math::Vec3d* value, int count) {
		glProgramUniform3dv(program, location, count, (const double*)value);
	}
	void Uniform(GLint location, const math::Vec4i* value, int count) {
		glProgramUniform4iv(program, location, count, (const int*)value);
	}
	void Uniform(GLint location, const math::Vec4ui* value, int count) {
		glProgramUniform4uiv(program, location, count, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Vec4f* value, int count) {
		glProgramUniform4fv(program, location, count, (const float*)value);
	}
	void Uniform(GLint location, const math::Vec4d* value, int count) {
		glProgramUniform4dv(program, location, count, (const double*)value);
	}
	void Uniform(GLint location, const math::Quati* value, int count) {
		glProgramUniform4iv(program, location, count, (const int*)value);
	}
	void Uniform(GLint location, const math::Quatui* value, int count) {
		glProgramUniform4uiv(program, location, count, (const unsigned int*)value);
	}
	void Uniform(GLint location, const math::Quatf* value, int count) {
		glProgramUniform4fv(program, location, count, (const float*)value);
	}
	void Uniform(GLint location, const math::Quatd* value, int count) {
		glProgramUniform4dv(program, location, count, (const double*)value);
	}
	void Uniform(GLint location, const math::Mat4f* value, int count) {
		glProgramUniformMatrix4fv(program, location, count, false, (const float*)value);
	}
	void Uniform(GLint location, const math::Mat4d* value, int count) {
		glProgramUniformMatrix4dv(program, location, count, false, (const double*)value);
	}
	void UniformBuffer(GLint location, const UniformBufferObject& value) {
		STAMPDMSG("render::ShaderProgramBase::uniformBuffer - function not implemented");
		//STAMPERROR(!value.isActive(), "render::ShaderProgramBase::uniformBuffer - UBO is not active");
		glUniformBlockBinding(program, location, value.blockIndex);
	}
	//void ShaderStorageBuffer(GLint location, const ShaderStorageBufferObject& value) {
	//	STAMPERROR(value.isActive(), "render::ShaderProgramBase::uniformBuffer - UBO is not active");
	//	glShaderStorageBlockBinding(program, location, value.blockIndex);
	//}
	void UniformBuffer(GLint location, int index) {
		glUniformBlockBinding(program, location, index);
	}
	void ShaderStorageBuffer(GLint location, int index) {
		glShaderStorageBlockBinding(program, location, index);
	}
	GLint GetUniformLocation(const char* name) {
		return glGetUniformLocation(program, name);
	}
	GLint GetUniformBufferLocation(const char* name) {
		return glGetUniformBlockIndex(program, name);
	}
	GLint GetUniformIndex(const char* name) {
		return glGetProgramResourceIndex(program, GL_UNIFORM, name);
	}
	GLint GetUniformBlockIndex(const char* name) {
		return glGetProgramResourceIndex(program, GL_UNIFORM_BLOCK, name);
	}
	GLint GetShaderStorageIndex(const char* name) {
		return glGetProgramResourceIndex(program, GL_SHADER_STORAGE_BLOCK, name);
	}
};

STAMP_GRAPHICS_GL_NAMESPACE_END

#endif