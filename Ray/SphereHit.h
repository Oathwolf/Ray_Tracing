#pragma once
#ifndef SPHEREHIT
#define SPHEREHIT

#include"Hittable.h"
#include"../RayMaterial/RayMaterial.h"

class SphereHit :public Hittable
{
public:
	SphereHit()
	{

	}
	virtual bool Hit(Ray &ray) override
	{
		glm::vec3 oc = ray.GetOrigin() - position;
		float a = glm::dot(ray.GetDirection(), ray.GetDirection());
		float b = 2.0f*glm::dot(ray.GetDirection(), oc);
		float c = glm::dot(oc, oc) - r * r;
		float discriminant = b * b - 4.0f*a*c;
		if (discriminant >= 0)
		{
			float t1 = (-b - sqrt(discriminant)) / (2.0f*a);
			float t2 = (-b - sqrt(discriminant)) / (2.0f*a);
			if (t1 > 0&&t1<ray.GetDistance()&&abs(t1)>0.001f)
			{
				hitData.position = ray.GetOrigin() + ray.GetDirection()*t1;
				hitData.normal = glm::normalize(hitData.position - position);

				glm::vec3 ray_color = ray.GetColor();
				ray.SetColor(glm::vec3(ray_color.x*color.x, ray_color.y*color.y, ray_color.z*color.z));
				material->MaterialHit(ray, hitData);
				return true;
			}
			if (t2 > 0&&t2<ray.GetDistance()&&abs(t2)>0.001f)
			{
				hitData.position = ray.GetOrigin() + ray.GetDirection()*t2;
				hitData.normal = glm::normalize(hitData.position - position);

				glm::vec3 ray_color = ray.GetColor();
				ray.SetColor(glm::vec3(ray_color.x*color.x, ray_color.y*color.y, ray_color.z*color.z));
				material->MaterialHit(ray, hitData);
				return true;
			}
		}
		return false;
	}
	virtual bool TestHit(Ray &ray) override
	{
		glm::vec3 oc = ray.GetOrigin() - position;
		float a = glm::dot(ray.GetDirection(), ray.GetDirection());
		float b = 2.0f*glm::dot(ray.GetDirection(), oc);
		float c = glm::dot(oc, oc) - r * r;
		float discriminant = b * b - 4.0f*a*c;
		if (discriminant >= 0)
		{
			float t1 = (-b - sqrt(discriminant)) / (2.0f*a);
			float t2 = (-b - sqrt(discriminant)) / (2.0f*a);
			if (t1 > 0 && t1<ray.GetDistance() && abs(t1)>0.001f)
			{
				ray.SetDistance(t1);
				return true;
			}
			if (t2 > 0 && t2<ray.GetDistance() && abs(t2)>0.001f)
			{
				ray.SetDistance(t2);
				return true;
			}
		}
		return false;
	}
	glm::vec3 GetPosition()
	{
		return position;
	}
	void SetPosition(glm::vec3 position)
	{
		this->position = position;
	}
	glm::vec3 GetColor()
	{
		return color;
	}
	void SetColor(glm::vec3 color)
	{
		this->color = color;
	}
	float GetRadius()
	{
		return r;
	}
	void SetRadius(float r)
	{
		this->r = r;
	}
protected:
	glm::vec3 position;
	glm::vec3 color;
	float r;
};

class GlassSphere :public SphereHit {
public:
	GlassSphere()
	{
		material = std::make_shared<Glass>();
		SetPosition(glm::vec3(1,0, 2));
		SetColor(glm::vec3(0.8f, 0.8f, 0.8f));
		SetRadius(0.5f);
	}
protected:
};

class StandSphere :public SphereHit{
public:

	StandSphere()
	{
		material = std::make_shared<Lambertian>();
		SetPosition(glm::vec3(0, 0, 2));
		SetColor(glm::vec3(0.3f, 1.0f, 1.0f));
		SetRadius(0.5f);
	}
};

class BigSphere :public SphereHit {
public:
	BigSphere()
	{
		material = std::make_shared<Lambertian>();
		SetPosition(glm::vec3(0, -100.5, 2));
		SetColor(glm::vec3(1.0f, 0.4f, 0.7f));
		SetRadius(100.0f);
	}
};

class MirrorSphere :public SphereHit {
public:
	MirrorSphere()
	{
		material = std::make_shared<Mirror>();
		SetPosition(glm::vec3(-1, 0, 2));
		SetColor(glm::vec3(0.5f, 0.1f, 0.3f));
		SetRadius(0.5f);
	}
};
class MirrorDiffuseSphere :public SphereHit {
public:
	MirrorDiffuseSphere()
	{
		material = std::make_shared<MirrorDiffuse>();
		SetPosition(glm::vec3(1, 0, 2));
		SetColor(glm::vec3(1.0f, 1.0f, 1.0f));
		SetRadius(0.5f);
	}
};


#endif // !SPHEREHIT
