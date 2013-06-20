/*
 * Vec3f.h
 *
 *  Created on: Jun 20, 2013
 *      Author: Technius
 */

#ifndef VEC3F_H_
#define VEC3F_H_

#include <cmath>

class Vec3f {
public:
	Vec3f(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double x, y, z;
	virtual ~Vec3f();
	virtual double magnitude();
	virtual Vec3f normalize();
	virtual Vec3f operator + (const Vec3f);
	virtual Vec3f operator - (const Vec3f);
};

Vec3f Vec3f::operator + (const Vec3f param)
{
	return Vec3f(this->x + param.x, this->y + param.y, this->z + param.z);
}

Vec3f Vec3f::operator - (const Vec3f param)
{
	return Vec3f(this->x - param.x, this->y - param.y, this->z - param.z);
}

double Vec3f::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vec3f Vec3f::normalize()
{
	double mag = magnitude();
	if(mag == 0)mag = 0.0000001;
	return Vec3f(x/mag, y/mag, z/mag);
}
Vec3f::~Vec3f()
{

}

#endif /* VEC3F_H_ */
