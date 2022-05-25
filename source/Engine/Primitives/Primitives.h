#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <engine.h>

namespace primitives
{
	void GenBlock(VertexBuffer* vb, VertexBufferLayout* layout, IndexBuffer* ibo, VertexArray* vao, Shader* shader, 
		glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));


	void GenTriangle(VertexBuffer* vb, VertexBufferLayout* layout, IndexBuffer* ibo, VertexArray* vao, Shader* shader, 
		glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));


	float* GenCircleVertex(float radius);
	unsigned int* GenCircleIndex();
}


#endif
