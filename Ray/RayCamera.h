#pragma once
#ifndef RAYCAMERA_H
#define RAYCAMERA_H

#include<glm/glm/glm.hpp>

class  RayCamera {
public:
	RayCamera()
	{

	}
	float GetFocalLength()
	{
		return focal_length;
	}
	void SetFocalLength(float focal_length)
	{
		this->focal_length = focal_length;
	}
	float GetHorizontalNum()
	{
		return horizontal_num;
	}
	void SetHorizontalNum(float horizontal_num)
	{
		this->horizontal_num = horizontal_num;
	}
	float GetVerticalNum()
	{
		return vertical_num;
	}
	void SetVerticalNum(float vertical_num)
	{
		this->vertical_num = vertical_num;
	}
	glm::vec3 GetHorizontal()
	{
		return horizontal;
	}
	void SetHorizontal(glm::vec3 horizontal)
	{
		this->horizontal = horizontal;
	}
	glm::vec3 GetVertecal()
	{
		return vertical;
	}
	void SetVertical(glm::vec3 vertical)
	{
		this->vertical = vertical;
	}
	glm::vec3 GetPosition()
	{
		return position;
	}
	void SetPosition(glm::vec3 position)
	{
		this->position = position;
	}
	glm::vec3 GetRealHorizontal()
	{
		return horizontal * horizontal_num;
	}
	glm::vec3 GetRealVertical()
	{
		return vertical * vertical_num;
	}
protected:
	float focal_length;
	float horizontal_num;
	float vertical_num;
	glm::vec3 horizontal;
	glm::vec3 vertical;
	glm::vec3 position;
};


#endif // ! RAYCAMERA_H
