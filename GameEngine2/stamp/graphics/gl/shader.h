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


#include <string>
#include <iterator>
#include <algorithm>
#include <stamp/graphics/gl/define.h>
#include <stamp/memory.h>
#include <stamp/noncopyable.h>
#include <stamp/math/vector.h>
#include <stamp/math/matrix.h>
#include <stamp/graphics/gl/texture.h>
#include <stamp/debug.h>

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

	std::string to_definestring(shader_type_t type);
	GLenum to_glenum(shader_type_t type);
};

class IShaderProgram : STAMP_NAMESPACE::INonCopyable, public STAMP_NAMESPACE::enable_threadsafe_from_this<class IShaderProgram> {
private:
	GLuint program = 0;
	static inline thread_local GLuint currentProgram = 0;

	GLenum CompileShader(std::string& version, std::string& progTxt, shader_type_t type);
protected:
	IShaderProgram() {}
	void Compile(std::istream& prog, shader_type_t type, const std::vector<std::string>& defines = {});
public:
	IShaderProgram(const IShaderProgram& other) = delete;
	IShaderProgram(IShaderProgram&& other) noexcept;
	IShaderProgram& operator =(const IShaderProgram& other) = delete;
	IShaderProgram& operator =(IShaderProgram&& other) noexcept;
	virtual ~IShaderProgram();

	int ProgramID();
	void Bind();
	bool isValid() const;
	//void Uniform(GLint location, const SamplerBase* value) {
	//	STAMPDMSG("render::ShaderProgramBase::Uniform - function not implemented");
	//	//STAMPASSERT(!value->isActive(), "render::ShaderProgramBase::uniform - texture is not active");
	//	glProgramUniform1i(program, location, value->GetActiveTextureIndex());
	//	std::cout << "render::ShaderProgramBase::uniformD - index: " << value->GetActiveTextureIndex() << " loc: " << location << " prog: " << program << std::endl;
	//	GLSTAMPASSERT;
	//}
	void Uniform(GLint location, const Texture& texture);
	void Uniform(GLint location, int value);
	void Uniform(GLint location, unsigned int value);
	void Uniform(GLint location, float value);
	void Uniform(GLint location, double value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2i& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2ui& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2f& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector2d& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3i& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3ui& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3f& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector3d& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4i& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4ui& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4f& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Vector4d& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix3f& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix3d& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix4f& value);
	void Uniform(GLint location, const STAMP_MATH_NAMESPACE::Matrix4d& value);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<int> Iter>									void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<int> Iter>								void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<unsigned int> Iter>						void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<unsigned int> Iter>						void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<float> Iter>								void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<float> Iter>							void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<double> Iter>								void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<double> Iter>							void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2i> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2i> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2ui> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2ui> Iter>	void Uniform(GLint location, Iter begin, Iter end);
	
	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2f> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2f> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2d> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector2d> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3i> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3i> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3ui> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3ui> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3f> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3f> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3d> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector3d> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4i> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4i> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4ui> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4ui> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4f> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4f> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4d> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Vector4d> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3f> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3f> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3d> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix3d> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4f> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4f> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	template<STAMP_NAMESPACE::forward_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4d> Iter>		void Uniform(GLint location, Iter begin, Iter end);
	template<STAMP_NAMESPACE::contiguous_iterator_derefrence_to<STAMP_MATH_NAMESPACE::Matrix4d> Iter>	void Uniform(GLint location, Iter begin, Iter end);

	//void ShaderStorageBuffer(GLint location, const ShaderStorageBufferObject& value) {
	//	STAMPASSERT(value.isActive(), "render::ShaderProgramBase::uniformBuffer - UBO is not active");
	//	glShaderStorageBlockBinding(program, location, value.blockIndex);
	//}
	void UniformBuffer(GLint location, int index);
	void ShaderStorageBuffer(GLint location, int index);
	GLint GetUniformLocation(const char* name);
	GLint GetUniformBufferLocation(const char* name);
	GLint GetUniformIndex(const char* name);
	GLint GetUniformBufferIndex(const char* name);
	GLint GetShaderStorageBufferIndex(const char* name);
};

class RenderShaderProgram : public IShaderProgram {
	STAMP_MEMORY_THREADSAFE_FRIEND;

	RenderShaderProgram() {}
public:
	static STAMP_NAMESPACE::threadsafe_ptr<RenderShaderProgram> ParseStream_glsl(std::istream& prog, shader_type_t type, const std::vector<std::string>& defines = {});
	STAMP_NAMESPACE::threadsafe_ptr<RenderShaderProgram> threadsafe_from_this();
};
class ComputerShaderProgram : public IShaderProgram {
	STAMP_MEMORY_THREADSAFE_FRIEND;

	ComputerShaderProgram() {}
public:
	static STAMP_NAMESPACE::threadsafe_ptr<ComputerShaderProgram> ParseStream_glsl(std::istream& prog, const std::vector<std::string>& defines = {});
	void Dispatch(int groupsX, int groupsY, int groupsZ);
	STAMP_NAMESPACE::threadsafe_ptr<ComputerShaderProgram> threadsafe_from_this();

	static int MaxDispatchInvocations();
	static int MaxDispatchPerGroup();
};

STAMP_GRAPHICS_GL_NAMESPACE_END

#endif