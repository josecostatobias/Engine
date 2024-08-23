#include "gpch.hpp"
#include "Runtime/Application.hpp"
#include "Presentation/Window.hpp"

Application::Application()
{

}

Application::~Application()
{
	delete Window;
}

void Application::Run()
{
	Window = new UWindow();
	Window->Initialize();



	GameLoop();
}

void Application::GameLoop()
{
	while(!Window->ShouldClose()) {
		Window->PollEvents();

		//iugum
	}
}
