#pragma once
#ifndef GLASS_H
#define GLASS_H

#include"../Ray/Ray.h"

class Glass :public Material
{
public:
	Glass()
	{
		refract = 1.5f;
	}
	virtual Ray MaterialHit(Ray &ray, HitData hitData) override
	{
		ray.SetOrigin(hitData.position);
		float refract_ratio = 1.0f;
		bool rayIn = false;
		if (glm::dot( hitData.normal,ray.GetDirection())<0.0f)
		{
			rayIn = true;
			refract_ratio = ray.GetRefract() / refract;
			ray.InputRefractStack(refract);
		}
		else
		{
			rayIn = false;
			ray.PopRefractStack();
			refract_ratio = refract / ray.GetRefract();
		}

		float cosTheta = abs(glm::dot(ray.GetDirection(), hitData.normal));
		float sinTheta = sqrt(1.0f - pow(cosTheta, 2));

		if (refract_ratio < 1.0f)
		{
			glm::vec3 ray_v = glm::normalize(glm::dot(ray.GetDirection(), hitData.normal)*hitData.normal);
			glm::vec3 ray_h = ray.GetDirection() - ray_v;
			glm::vec3 ray_direction = glm::normalize(ray_v + ray_h * refract_ratio);
			ray.SetDirection(ray_direction);
		}
		else
		{
			if (refract_ratio*sinTheta > 1.0f)
			{
				glm::vec3 reflect = glm::vec3(0, 0, 0);
				if (rayIn)
				{
					reflect = glm::normalize(ray.GetDirection() + 2.0f*hitData.normal);
					printf("yes\n");
				}
				else
				{
					reflect = glm::normalize(ray.GetDirection() - 2.0f*hitData.normal);
				}
				ray.SetDirection(reflect);
			}
			else
			{
				glm::vec3 ray_v = glm::normalize(glm::dot(ray.GetDirection(), hitData.normal)*hitData.normal);
				glm::vec3 ray_h = ray.GetDirection() - ray_v;
				glm::vec3 ray_direction = glm::normalize(ray_v + ray_h * refract_ratio);
				ray.SetDirection(ray_direction);
			}
		}
		
		return ray;
	}

protected:
	float refract;
};

#endif // !GLASS_H
