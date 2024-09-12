#include "gpch.hpp"
#include "Runtime/Application.hpp"
#include "SDL3/SDL_main.h"
#include "vulkan/vulkan.hpp"
#include <SDL3/SDL_vulkan.h>
#include "backends/imgui_impl_vulkan.h"

int main(int argc, char* argv []) {

	Application* app = new Application();

	VkInstance instance{};

	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Showbias";
	appInfo.applicationVersion = VK_MAKE_VERSION(0,0,0);
	appInfo.pEngineName = "TDroid";
	appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_3;

	VkInstanceCreateInfo instanceCreateInfo{};
	instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pApplicationInfo = &appInfo;

	if (vkCreateInstance(&instanceCreateInfo,nullptr, &instance) != VK_SUCCESS) {
		throw std::runtime_error("falha ao criar instace do vulkan!");
	}
	
	app->Run();
	delete app;
	return 0;
}