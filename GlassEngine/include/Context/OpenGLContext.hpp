#ifndef OPENGL_CONTEXT_HPP
#define OPENGL_CONTEXT_HPP

#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <string>

class OpenGLContext {
public:
    OpenGLContext(SDL_Window* window);
    ~OpenGLContext();

    void Initialize(); // Configurações iniciais do OpenGL
    void SwapBuffers(); // Troca de buffers da janela
    SDL_GLContext GetGLContext() const;

private:
    SDL_Window* sdlWindow;       // Ponteiro para a janela associada
    SDL_GLContext glContext;     // Contexto do OpenGL
};

#endif // OPENGL_CONTEXT_HPP