#pragma once
#include <SDL3/SDL.h>
class OpenGLRenderer {
public:
    OpenGLRenderer(SDL_Window* window);
    ~OpenGLRenderer();

    void Render();

private:
    void InitializeOpenGL();

    void SetupTriangle();

    SDL_Window* sdlWindow;
    SDL_GLContext glContext;
};