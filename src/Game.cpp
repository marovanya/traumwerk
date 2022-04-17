#include <cstdlib>
#include <cstdio>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Game.hpp"

Game::Game() {
    this->is_running = false;
}

bool Game::isRunning(){
    return this->is_running;
}

int Game::start() {

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialzie GLFW :(\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    is_running = true;

    // Open a window and creat its OpenGL contxt
    window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    if (!window) {
        fprintf( stderr, "Failed to open GLFW window. :(\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW|
    if (glewInit() != GLEW_OK) {
        fprintf( stderr, "Failed to initialize GLEW unu\n");
        getchar();
        glfwTerminate();
        return -1;
    }
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    this->is_running = true;
    return 0;
}

void Game::handleInput() {
	glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || 
        glfwWindowShouldClose(window) != 0)
        {
            this->quit();
        }
}

void Game::update(double deltaTime) {

}

void Game::render() {
	
	// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
	glClear( GL_COLOR_BUFFER_BIT );

	// Draw nothing, see you in tutorial 2 !

	// Swap buffers
	glfwSwapBuffers(window);

}

void Game::quit() {
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}


