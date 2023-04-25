#include <OGL3D/GraphicsEngine/GraphicsEngine.h>
#include <glad/glad_wgl.h>								// All normal opengl functions
#include <glad/glad.h>									// All window os specific functions
#include <assert.h>
#include <stdexcept>
#include <OGL3D/Math/OVec4.h>

GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::clear(const OVec4& color)
{
	// Call opengl function
	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}


