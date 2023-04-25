#include <OGL3D/Game/OGame.h>
#include <OGL3D/Window/OWindow.h>
#include <OGL3D/GraphicsEngine/GraphicsEngine.h>
#include <Windows.h>

OGame::OGame()
{
	m_display = std::make_unique<OWindow>();
	m_graphicsEngine = std::make_unique<GraphicsEngine>();

	// set opengl to our display on init
	m_display->makeCurrentContext();
}

OGame::~OGame()
{
	
}

void OGame::onCreate()
{
	m_graphicsEngine->clear(OVec4(1, 0, 0, 1));

	m_display->present(false);
}

void OGame::onUpdate()
{
}

void OGame::onQuit()
{
}

void OGame::run()
{
	onCreate();
	
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

		onUpdate();
	}

	onQuit();
}

void OGame::quit()
{
	m_isRunning = false;
}
