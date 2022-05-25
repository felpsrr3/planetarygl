#include <Simulation.h>

Body::Body()
{
	float radius = 10.0f;

	color = glm::vec4(0.0f, 0.7f, 0.5f, 1.0f);

	float h = radius * 0.7071067812f;
	float zero = 0.0f;

	float vertices[18] =
	{
		-radius, zero,
		-h, h,
		zero, zero,
		zero, radius,
		h, h,
		radius, zero,
		h, -h,
		zero, -radius,
		-h, -h
	};

	unsigned int indices[24] =
	{
		0, 1, 2,
		1, 3, 2,
		3, 4, 2,
		4, 5, 2,
		5, 6, 2,
		6, 7, 2,
		7, 8, 2,
		8, 0, 2
	};

	vao = new VertexArray();
	vb = new VertexBuffer(vertices, sizeof(vertices));
	layout = new VertexBufferLayout();

	layout->Push<float>(2);

	vao->Bind();
	vao->AddBuffer(*vb, *layout);

	shader = new Shader("source/Engine/Shader/primitive.shader");

	ibo = new IndexBuffer(indices, sizeof(indices));

	shader->Bind();
	shader->SetUniform4f("uColor", color[0], color[1], color[2], color[3]);

	model = glm::translate(glm::mat4(1.0f), glm::vec3(300.0f, 300.0f, 0.0f));
}

void Body::OnRender(Renderer* renderer, glm::mat4 projection)
{
	glm::mat4 projectionModel = projection * glm::mat4(1.0f) * model;
	shader->Bind();
	shader->SetUniformMat4f("uProjectionModel", projectionModel);

	renderer->Draw(vao, ibo, shader);
}