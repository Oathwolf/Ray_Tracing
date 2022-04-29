#pragma once
#ifndef  RAYHITTABLELIST_H
#define RAYHITTABLELIST_H

#include"Hittable.h"

class RayHittableManager {

public:
	static RayHittableManager* GetRayHittableManager()
	{
		static RayHittableManager instance;
		return &instance;
	}

	std::list< std::shared_ptr<Hittable>>* GetHittableList()
	{
		return &hit_array;
	}
	void InputHittableList(std::shared_ptr<Hittable> hittable)
	{
		hit_array.push_back(hittable);
	}

private:
	RayHittableManager()
	{

	}
	std::list< std::shared_ptr<Hittable>> hit_array;
};

#endif // ! RAYHITTABLELIST_H
