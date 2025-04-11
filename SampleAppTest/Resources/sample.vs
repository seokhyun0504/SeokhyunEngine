#version 410 core

layout (location = 0) in vec3 a_Position;

uniform mat4 u_modelMat;

out vec3 v_Position;

void main(void)
{
    v_Position = a_Position;
	gl_Position = u_modelMat * vec4(a_Position, 1.0);
}