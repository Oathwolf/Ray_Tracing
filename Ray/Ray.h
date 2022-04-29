#pragma once
#ifndef RAY_H
#define RAY_H
#include<glm/glm/glm.hpp>

const float MAX_DISTANCE = 1000000.0f;

class Ray {

public:
	Ray()
	{
		distance = MAX_DISTANCE;
		refrect_stack.push_back(1.0f);
	}
	Ray(glm::vec3 origin,glm::vec3 direction)
	{
		this->origin = origin;
		this->direction = glm::normalize(direction);
		distance = MAX_DISTANCE;
		refrect_stack.push_back(1.0f);
	}
	glm::vec3 GetOrigin()
	{
		return origin;
	}
	void SetOrigin(glm::vec3 origin)
	{
		this->origin = origin;
	}
	glm::vec3 GetDirection()
	{
		return direction;
	}
	void SetDirection(glm::vec3 direction)
	{
		this->direction = direction;
	}
	glm::vec3 GetColor()
	{
		return color;
	}
	void SetColor(glm::vec3 color)
	{
		this->color = color;
	}
	float GetDistance()
	{
		return distance;
	}
	void SetDistance(float distance)
	{
		this->distance = distance;
	}
	float GetRefract()
	{
		if(!refrect_stack.empty())
		return refrect_stack.back();
		else
		{
			printf("empty\n");
		}
		return 1.0f;
	}
	void InputRefractStack(float refract)
	{
		refrect_stack.push_back(refract);
	}
	void PopRefractStack()
	{
		if(refrect_stack.empty())
		refrect_stack.pop_back();
		else
		{
			printf("empty\n");
		}
	}

protected:

	std::vector<float> refrect_stack;

	glm::vec3 origin;
	glm::vec3 direction;
	glm::vec3 color;

	float distance;
};


#endif