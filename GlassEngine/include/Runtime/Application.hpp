#pragma once

#ifndef US_APPLICATION_HPP
#define	US_APPLICATION_HPP

class UWindow;

class Application
{
public:
	Application();
	~Application();
	void Run();
	void GameLoop();
	UWindow* Window = nullptr;

};



#endif // !US_APPLICATION_HPP