#pragma once

#include <engine.h>

#ifndef BODY_H
#define BODY_H


class Body
{
public:
	Body();
	inline void TranslateBody(glm::mat4 pos) { model = pos; }

	void OnRender(Renderer* renderer, glm::mat4 projection);

private:
	glm::mat4 model;
	glm::vec4 color;

	Shader* shader;
	VertexBuffer* vb;
	VertexBufferLayout* layout;
	IndexBuffer* ibo;
	VertexArray* vao;
};

#endif


#ifndef SIMULATION_H
#define SIMULATION_H

#include <engine.h>

class Simulation
{
public:
	Simulation(unsigned int height, unsigned int width, GLFWwindow* window);

	void AddBody(const std::string& type);

	void OnUpdate(float deltaTime);
	void OnRender();
	
private:
	glm::mat4 projection;
	GLFWwindow* window;

	Renderer* renderer;

	std::vector<Body*> Bodies;
};

#endif
