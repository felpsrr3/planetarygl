#include <Simulation.h>

Simulation::Simulation(unsigned int height, unsigned int width, GLFWwindow* window) : window(window)
{
	projection = glm::ortho(0.0f, (float)height, 0.0f, (float)width, -1.0f, 1.0f);
	renderer = new Renderer();

	AddBody("Sphere");
}

void Simulation::AddBody(const std::string& type)
{
	if (type == "Sphere")
	{
		Body* tempBody = new Body();
		Bodies.push_back(tempBody);
	}
}

void Simulation::OnUpdate(float deltaTime)
{
	if (!Bodies.empty())
	{
	}
}

void Simulation::OnRender()
{
	if (!Bodies.empty())
	{
		renderer->Clear();

		Bodies[0]->OnRender(renderer, projection);
	}
}