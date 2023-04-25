#include <OGL3D/Window/OWindow.h>
#include <Windows.h>
#include <assert.h>
#include <glad/glad_wgl.h>								// All normal opengl functions
#include <glad/glad.h>									// All window os specific functions
#include <stdexcept>


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		OWindow* window = (OWindow *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return NULL;
}

OWindow::OWindow()
{
	WNDCLASSEX windowClass = {};
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.lpszClassName = L"OpenGLWindow";
	windowClass.lpfnWndProc = &WndProc;

	// Let OS know about class and register it by passing address of the var
	auto classID = RegisterClassEx(&windowClass);
	assert(classID);

	RECT rect = { 0, 0, 1024, 768 };
	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	 m_Handle = CreateWindowEx(NULL, MAKEINTATOM(classID), L"GameEngine",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, NULL, NULL);

	 assert(m_Handle);

	 SetWindowLongPtr((HWND)m_Handle, GWLP_USERDATA, (LONG_PTR)this);

	 ShowWindow((HWND)m_Handle, SW_SHOW);
	 UpdateWindow((HWND)m_Handle);

	 // Surface of the window through the Device Context
	 auto windowDC = GetDC((HWND)m_Handle);

	 PIXELFORMATDESCRIPTOR pixelFormatDescriptor = {};
	 pixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	 pixelFormatDescriptor.nVersion = 1;
	 pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	 pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	 pixelFormatDescriptor.cColorBits = 32;
	 pixelFormatDescriptor.cAlphaBits = 8;
	 pixelFormatDescriptor.cDepthBits = 24;
	 pixelFormatDescriptor.cStencilBits = 8;
	 pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;


	 // Init opengl
	 // Function allows retrieval a specific pixel format to set for the window that was created.
	 auto pixelFormat = ChoosePixelFormat(windowDC, &pixelFormatDescriptor);
	 // Set it to the surface of the window and make it opengl ready
	 SetPixelFormat(windowDC, pixelFormat, &pixelFormatDescriptor);

	 // opengl context
	 auto windowContext = wglCreateContext(windowDC);
	 assert(windowContext);

	 // Set context as current contexts, opengl will refer to this now
	 // Init all opengl functions
	 wglMakeCurrent(windowDC, windowContext);

	 if (!gladLoadWGL(windowDC))
	 {
		 throw std::runtime_error("GraphicsEngine - Error - GLADLoadWGL failed.");
	 }

	 if (!gladLoadGL())
	 {
		 throw std::runtime_error("GraphicsEngine - Error - GLADLoadGL failed.");
	 }

	 // Opengl loaded
	 wglMakeCurrent(windowDC, 0);
	 ShowWindow((HWND)m_Handle, SW_SHOW);
	 UpdateWindow((HWND)m_Handle);;
}

OWindow::~OWindow()
{
	DestroyWindow((HWND)m_Handle);
}

