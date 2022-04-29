#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H

#include"Ray.h"
#include"Hittable.h"

class Material {
public:
	Material()
	{

	}
	virtual Ray MaterialHit(Ray &ray, HitData hitData) = 0;
};

#endif // !MATERIAL_H
