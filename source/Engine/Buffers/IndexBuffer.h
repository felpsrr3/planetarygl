#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <GL/glew.h>

class IndexBuffer
{
private:
	GLuint m_RendererID;
	GLuint m_Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count);

	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return m_Count; }
	inline unsigned int GetBuffer() const { return m_RendererID; }
};
#endif