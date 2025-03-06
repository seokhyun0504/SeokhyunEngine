#version 410 core

in vec3 v_Position;

out vec4 color;

void main(void)
{
    color = vec4(v_Position * 0.5 + 0.5, 1.0);
}