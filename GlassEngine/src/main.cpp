#include "gpch.hpp"
#include "Runtime/Application.hpp"
#include "SDL3/SDL.h"
#include "Presentation/Window.hpp"
int main() {

	UWindow* app = new UWindow();
	
	app->initialize();
	while (true){
		
	}
	delete app;
	return 0;
}