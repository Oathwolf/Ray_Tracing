#version 330 core
layout(location = 0)in vec2 aPos;
layout(location = 1)in vec2 aTexture;

out vec2 Tex;

void main()
{
	Tex = aTexture;
	gl_Position = vec4(aPos,0.0f,1.0f);
}