#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <Windows.h>

OGame::OGame()
{
	m_display = std::unique_ptr<OWindow>(new OWindow());
}

OGame::~OGame()
{
	
}

void OGame::run()
{
	MSG message;
	while (m_isRunning && !m_display->isClosed())
	{
		if (PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		Sleep(1.5F);
	}
}

void OGame::quit()
{
	m_isRunning = false;
}
