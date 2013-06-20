/*
 * Rect.h
 *
 *  Created on: Jun 19, 2013
 *      Author: Technius
 */

#ifndef RECT_H_
#define RECT_H_

#include <SFML/OpenGL.hpp>

class Rect3d
{
public:
	Vec3d *p1, *p2;
	Rect3d(Vec3d p1, Vec3d p2)
	{
		this->p1 = &p1;
		this->p2 = &p2;
	}
	virtual ~Rect3d();
	virtual void render(Vec3d cam);
};

void Rect3d::render(Vec3d cam)
{
	Vec3d *a = &cam;
	Vec3d *b = this->p1;
	Vec3d *c = this->p2;
	Vec3d p1 = *b + *a;
	Vec3d p2 = *c + *a;
	glBegin(GL_QUADS);
	//Front face
	glColor3f(1, 0, 0);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p1.z);
	glVertex3f(p1.x, p2.y, p1.z);
	//Back face
	glColor3f(1, 0, 0);
	glVertex3f(p1.x, p1.y, p2.z);
	glVertex3f(p2.x, p1.y, p2.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p1.x, p2.y, p2.z);
	//X P1
	glColor3f(0, 1, 0);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p1.x, p1.y, p2.z);
	glVertex3f(p1.x, p2.y, p2.z);
	glVertex3f(p1.x, p2.y, p1.z);
	//X P2
	glColor3f(0, 1, 0);
	glVertex3f(p2.x, p1.y, p1.z);
	glVertex3f(p2.x, p1.y, p2.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p2.x, p2.y, p1.z);
	//Top
	glColor3f(0, 0, 1);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p1.y, p1.z);
	glVertex3f(p2.x, p1.y, p2.z);
	glVertex3f(p1.x, p1.y, p2.z);
	//Bottom
	glColor3f(0, 0, 1);
	glVertex3f(p1.x, p2.y, p1.z);
	glVertex3f(p2.x, p2.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p1.x, p2.y, p2.z);
	glEnd();
	delete b;
	delete c;
	delete a;
}

Rect3d::~Rect3d()
{
	delete this->p1;
	delete this->p2;
}


#endif /* RECT_H_ */
