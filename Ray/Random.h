#pragma once
#ifndef RANDOW_H
#define RANDOW_H
#include<random>

float GetRandom0_1()
{
	return (float)rand() / (float)(RAND_MAX+1);
}

float GetCommonRandom(float min, float max)
{
	float num = min + (max - min)*GetRandom0_1();
	return num;
}
glm::vec3 GetVec3Random(float min1, float max1, float min2, float max2, float min3, float max3)
{
	return glm::vec3(GetCommonRandom(min1, max1), GetCommonRandom(min2, max2), GetCommonRandom(min3, max3));
}

glm::vec3 GetInUnitSphereRandom()
{
	while (true)
	{
		glm::vec3 p = GetVec3Random(-1, 1, -1, 1, -1, 1);
		if (glm::length(p) > 1)
		{
			continue;
		}
		return glm::normalize(p);
	}
}


#endif // !RANDOW_H
