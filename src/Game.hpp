// #include <GLFW/glfw3.h>
class Game {
    public:
        Game();
        int start();
        bool isRunning();
        void handleInput();
        void update(double deltaTime);
        void render();
        void quit();
    private:
        bool is_running;
        GLFWwindow* window;
};