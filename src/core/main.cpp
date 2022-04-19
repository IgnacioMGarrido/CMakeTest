#include <GLFW/glfw3.h>
#include <iostream>
#include <LegioConfig.h>

int main(int argc, char* argv[])
{
    std::cout << argv[0] << " Version: " << LEGIO_VERSION_MAJOR << "." << LEGIO_VERSION_MINOR << '\n'; 
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

    }

    glfwTerminate();
    return 0;
}