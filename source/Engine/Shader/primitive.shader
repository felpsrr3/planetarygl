#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 uProjectionModel;

void main()
{
	gl_Position = uProjectionModel * position;
}

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 uColor;

void main()
{
	color = uColor;
}