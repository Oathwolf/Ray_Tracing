#pragma once
#ifndef MIRROR_H
#define MIRROR_H

#include"../Ray/Material.h"
#include"../Ray/Random.h"

class Mirror :public Material
{
public:
	Mirror()
	{

	}
	virtual Ray MaterialHit(Ray &ray, HitData hitData) override
	{
		ray.SetOrigin(hitData.position);
		glm::vec3 reflect = glm::normalize(ray.GetDirection() + 2.0f*hitData.normal);
		ray.SetDirection(reflect);
		return ray;
	}
};

class MirrorDiffuse :public Material
{
public:
	MirrorDiffuse()
	{
		diffuse = 0.7f;
	}
	MirrorDiffuse(float diffuse) :diffuse(diffuse)
	{

	}
	virtual Ray MaterialHit(Ray &ray, HitData hitData) override
	{
		ray.SetOrigin(hitData.position);
		glm::vec3 reflect = glm::normalize(ray.GetDirection() + 2.0f*hitData.normal);
		glm::vec3 random_direction = GetInUnitSphereRandom();
		glm::vec3 ray_direction = glm::normalize(reflect + diffuse*random_direction);
		ray.SetDirection(ray_direction);
		return ray;
	}
protected:
	float diffuse;
};

#endif // !MIRROR_H
