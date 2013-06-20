/*
 * Vec3d.h
 *
 *  Created on: Mar 3, 2013
 *      Author: Technius
 */

#ifndef VEC3D_H_
#define VEC3D_H_

#include <cmath>

class Vec3d {
public:
	Vec3d(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double x, y, z;
	virtual ~Vec3d();
	virtual double magnitude();
	virtual Vec3d normalize();
	virtual Vec3d operator + (const Vec3d);
	virtual Vec3d operator - (const Vec3d);
};

Vec3d Vec3d::operator + (const Vec3d param)
{
	return Vec3d(this->x + param.x, this->y + param.y, this->z + param.z);
}

Vec3d Vec3d::operator - (const Vec3d param)
{
	return Vec3d(this->x - param.x, this->y - param.y, this->z - param.z);
}

double Vec3d::magnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vec3d Vec3d::normalize()
{
	double mag = magnitude();
	if(mag == 0)mag = 0.0000001;
	return Vec3d(x/mag, y/mag, z/mag);
}
Vec3d::~Vec3d()
{

}

#endif /* VEC3D_H_ */
