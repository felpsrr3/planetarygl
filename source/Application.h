#ifndef APPLICATION_H
#define APPLICATION_H

#include <engine.h>
#include <Planetary/Simulation.h>

class Application
{
public:
	Application(unsigned int screenHeight, unsigned int screenWidth) : screenHeight(screenHeight), screenWidth(screenWidth), deltaTime(0.0f), lastTime(0.0f), currentTime(0.0f)
	{
        if (!glfwInit())
            std::cout << "GLFW INIT ERROR!\n";

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

        window = glfwCreateWindow(screenHeight, screenWidth, "Tab", NULL, NULL);
        if (window == GLFW_FALSE)
        {
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        GLenum error = glewInit();
        if (GLEW_OK != error)
        {
            std::cout << "Error: %s\n" << glewGetErrorString(error);
        }
        std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
        std::cout << "GL Version: " << glGetString(GL_VERSION) << std::endl;

        Sim = new Simulation(screenHeight, screenWidth, window);
	}

    void GameLoop()
    {
        while (!glfwWindowShouldClose(window))
        {
            deltaTimeCalc();

            Sim->OnUpdate(deltaTime);
            Sim->OnRender();

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
        glfwTerminate();
    }
private:
    void deltaTimeCalc()
    {
        currentTime = static_cast<float>(glfwGetTime());
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;
    }

private:
	GLFWwindow* window;
    unsigned int screenHeight;
    unsigned int screenWidth;

    Simulation* Sim;

    float deltaTime;
    float lastTime;
    float currentTime;
};

#endif