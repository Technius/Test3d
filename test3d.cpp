/*
 * test3d.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: Technius
 */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include "Vec3d.h"
#include "Rect3d.h"
#include "Vec3f.h"
using namespace std;

void perspectiveGL(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;
	fH = tan((fovY/2)/180*pi)*zNear;
	fH = tan(fovY/360*pi)*zNear;
	fW = fH*aspect;
	glFrustum(-fW, fW, -fH, fH, zNear, zFar);
}

void initGL(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	perspectiveGL(60, width/height, 0.01, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}

double toRad(double deg)
{
	return deg*M_PI/180;
}

int main()
{
	const int width = 1280, height = 720;
    sf::RenderWindow App(sf::VideoMode(width, height, 32), "Test 3D", sf::Style::Fullscreen);
    initGL(width, height);
    Vec3d pos(0, 0, -3);
    Vec3f rot(0, 0, 0);
    App.setFramerateLimit(60);
    Rect3d r(Vec3d(0, 0, 0), Vec3d(1, 1, 1));
    while(App.isOpen())
    {
    	sf::Event event;
    	while(App.pollEvent(event))
    	{
    		if(event.type == sf::Event::Closed)App.close();
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    	{
    		if(rot.y == 0)pos.z += 0.01;
    		else
    		{
    			double ry = toRad(rot.y);
    			pos.z += 0.01*sin(ry);
    			pos.x += 0.01*cos(ry);
    		}
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    	{
    		if(rot.y == 0)pos.z += 0.01;
    		else
    		{
    			double ry = toRad(rot.y + 180);
    			pos.z += 0.01*sin(ry);
    			pos.x += 0.01*cos(ry);
    		}
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    	{
    		if(rot.y == 0)pos.z += 0.01;
    		else
    		{
    			double ry = toRad(rot.y + 90);
    			pos.z += 0.01*sin(ry);
    			pos.x += 0.01*cos(ry);
    		}
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    	{
    		if(rot.y == 0)pos.z -= 0.01;
    		else
    		{
    			double ry = toRad(rot.y + 90);
    			pos.z -= 0.01*sin(ry);
    			pos.x -= 0.01*cos(ry);
    		}
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))rot.x == 0 ? rot.x = 359 : rot.x -= 1;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))rot.x == 359 ? rot.x = 0 : rot.x += 1;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))pos.y += 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))pos.y -= 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))rot.y == 0 ? rot.y = 359 : rot.y -= 1;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))rot.y == 359 ? rot.y = 0 : rot.y += 1;
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();
    	glRotatef(rot.x, 1, 0, 0);
    	glRotatef(rot.y, 0, 1, 0);
    	r.render(pos);
    	App.display();
    }
    return 0;
}
