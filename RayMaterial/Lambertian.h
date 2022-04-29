#pragma once
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include"../Ray/Material.h"
#include"../Ray/Random.h"

class Lambertian :public Material
{
public:
	Lambertian()
	{

	}

	virtual Ray MaterialHit(Ray &ray, HitData hitData) override
	{
		ray.SetOrigin(hitData.position);
		ray.SetDirection(glm::normalize(hitData.normal + GetInUnitSphereRandom()));
		ray.SetColor(0.8f*ray.GetColor());
		return ray;
	}
};

#endif // !LAMBERTIAN_H
