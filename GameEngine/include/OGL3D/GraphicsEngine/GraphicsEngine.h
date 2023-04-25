#pragma once
#include <Windows.h>

class OWindow;

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();
private:
	HWND m_windowHandle;
};

