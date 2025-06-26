#include "gpch.hpp"
#include "Runtime/Application.hpp"
#include "SDL3/SDL_main.h"
#include "vulkan/vulkan.hpp"
#include <SDL3/SDL_vulkan.h>
#include "backends/imgui_impl_vulkan.h"

int main(int argc, char* argv []) {

	Application* app = new Application();

	
	app->Run();
	delete app;
	return 0;
}