#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>

class Application
{
public:
    void run()
    {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    GLFWwindow* window;

    void initWindow()
    {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(960, 540, "Vulkan", nullptr, nullptr);
    }

    void initVulkan() { }

    void mainLoop() { while (!glfwWindowShouldClose(window)) glfwPollEvents(); }

    void cleanup()
    {
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

int main()
{
    try
    {
        Application app;
        app.run();
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what();
    }
}