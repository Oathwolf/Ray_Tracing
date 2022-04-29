#version 330 core
out vec4 FragColor;
in vec2 Tex;

uniform sampler2D boradTexture;

void main()
{
	vec3 col = texture(boradTexture,Tex).rgb;
	FragColor = vec4(col,1.0f);
}