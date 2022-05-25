#include "Renderer.h"

void Renderer::Clear() const
{
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(VertexArray* va, IndexBuffer* ib, Shader* shader)
{
	ib->Bind();
	va->Bind();
	shader->Bind();

	glDrawElements(GL_TRIANGLES, ib->GetCount()/sizeof(GLuint), GL_UNSIGNED_INT, nullptr);

}