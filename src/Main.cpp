#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Game.hpp"

int main(void) {
    Game game = Game();

    if (game.start() != 0) {
        fprintf(stderr, "Failed to start game :( Bye\n");;
        getchar();
        return -1;
    }

    glfwSetTime(0.0);
    double ticksLastFrame = 0;
    double deltaTime;
    
    printf("Success\n");

    while (game.isRunning()) {
        deltaTime = glfwGetTime() - ticksLastFrame;

        game.handleInput();
        game.update(deltaTime);
        game.render();
        
        ticksLastFrame = glfwGetTime();
    }
}

