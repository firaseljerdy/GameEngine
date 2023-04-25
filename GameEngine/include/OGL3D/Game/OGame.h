#pragma once
#include <memory>

class GraphicsEngine;
class OWindow;
class OGame
{
public:
	OGame();
	~OGame();
	void run();
	void quit();
protected:
	bool m_isRunning = true;
	std::unique_ptr<GraphicsEngine> m_graphicsEngine;
	std::unique_ptr<OWindow> m_display;
};

