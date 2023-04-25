#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <Windows.h>

OGame::OGame()
{
	m_display = std::make_unique<OWindow>();
}

OGame::~OGame()
{
	
}

void OGame::run()
{
	
	while (m_isRunning)
	{
		MSG message = {};
		if (PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				m_isRunning = false;
				continue;
			}
			else
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			
		}

		Sleep(1.0F);
	}
}

void OGame::quit()
{
	m_isRunning = false;
}
