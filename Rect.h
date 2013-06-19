/*
 * Rect.h
 *
 *  Created on: Jun 19, 2013
 *      Author: Technius
 */

#ifndef RECT_H_
#define RECT_H_

#include <SFML/OpenGL.hpp>

class Rect
{
public:
	Rect(const Vec3d p1, const Vec3d p2)
	{
		this->p1 = &p1;
		this->p2 = &p2;
	}
	Vec3d *p1, *p2;
	virtual ~Rect();
	virtual void render(Vec3d cam);
};

void Rect::render(Vec3d cam)
{
	Vec3d p1 = this->p1 + cam;
	Vec3d p2 = this->p2 + cam;
	glBegin(GL_QUADS);
	//Front face
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p1.z);
	glVertex3f(p1.x, p2.y, p1.z);
	glEnd();
}

Rect::~Rect()
{

}


#endif /* RECT_H_ */
