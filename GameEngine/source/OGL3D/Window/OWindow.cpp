#include <OGL3D/Window/OWindow.h>
#include <Windows.h>
#include <assert.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		OWindow* window = (OWindow *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
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
	assert(RegisterClassEx(&windowClass));
	RECT rect = { 0, 0, 1024, 768 };
	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	 m_Handle = CreateWindowEx(NULL, L"OpenGLWindow", L"GameEngine", 
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 
		rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, NULL, NULL);

	 assert(m_Handle);

	 SetWindowLongPtr((HWND)m_Handle, GWLP_USERDATA, (LONG_PTR)this);

	 ShowWindow((HWND)m_Handle, SW_SHOW);
	 UpdateWindow((HWND)m_Handle);
}

OWindow::~OWindow()
{
	DestroyWindow((HWND)m_Handle);
}

void OWindow::onDestroy()
{
	m_Handle = nullptr;
}

bool OWindow::isClosed()
{
	// if the handle is null the window is closed
	return !m_Handle;
}
