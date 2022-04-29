#pragma once
#ifndef HITTABLE_H
#define HITTABLE_H

typedef struct HitData
{
	glm::vec3 position;
	glm::vec3 normal;

}HitData;

#include"Ray.h"
#include"Material.h"

class Hittable {
public:
	Hittable()
	{

	}
	virtual bool TestHit(Ray &ray) = 0;
	virtual bool Hit(Ray &ray) = 0;

protected:
	bool isHit;
	HitData hitData;
	std::shared_ptr<Material> material;
	
};

#endif // !HITTABLE
