#pragma once
class OWindow
{
public:
	OWindow();
	~OWindow();

	void makeCurrentContext();
	void present(bool vsync);

private:
	void* m_Handle = nullptr;
	void* m_context = nullptr;
};

