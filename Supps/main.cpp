#include <OGL3D/Game/OGame.h>
#include <iostream>

int main()
{
	try
	{
		OGame gameInstance;
		gameInstance.run();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}