#pragma once
#include <Windows.h>
#include <OGL3D/Math/OVec4.h>

class OWindow;

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

public:
	void clear(const OVec4 &color);
private:
	HWND m_windowHandle;
};

