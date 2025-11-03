#include <iostream>
#include <stamp/graphics/gl/define.h>

bool STAMP_GRAPHICS_GL_NAMESPACE::checkOpenGLErrors() {
	GLenum error = glGetError();
	bool k = false;
	while (error != GL_NO_ERROR) {
		k = true;
		// Handle the error appropriately
		std::cout << "OpenGL error: (" << error << ") ";
		switch (error) {
		case GL_INVALID_ENUM:
			std::cout << "invalid enum";
			break;
		case GL_INVALID_VALUE:
			std::cout << "invalid value";
			break;
		case GL_INVALID_OPERATION:
			std::cout << "invalid operation";
			break;
		case GL_STACK_OVERFLOW:
			std::cout << "stack overflow";
			break;
		case GL_STACK_UNDERFLOW:
			std::cout << "stack underflow";
			break;
		case GL_OUT_OF_MEMORY:
			std::cout << "out of memory";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cout << "invalid framebuffer operation";
			break;
		case GL_CONTEXT_LOST:
			std::cout << "context lost";
			break;
		case GL_TABLE_TOO_LARGE:
			std::cout << "table too large";
			break;
		}
		std::cout << std::endl;
		error = glGetError();
	}
	return k;
}