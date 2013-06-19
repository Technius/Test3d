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
#include "Rect.h"
using namespace std;

void perspectiveGL(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	const GLdouble pi = 3.1415926535897932384626433832795;
	GLdouble fW, fH;
	fH = tan( (fovY / 2) / 180 * pi ) * zNear;
	fH = tan( fovY / 360 * pi ) * zNear;
	fW = fH * aspect;
	glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}

void initGL(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	perspectiveGL(60, width/height, 0.01, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}

int main()
{
	const int width = 1280, height = 720;
    sf::RenderWindow App(sf::VideoMode(width, height, 32), "Test 3D", sf::Style::Fullscreen);
    initGL(width, height);
    Vec3d pos(0, 0, 0);
    App.setFramerateLimit(60);
    float yaw = 0;
    Rect r(Vec3d(0, 0, 0), Vec3d(1, 1, 1));
    while(App.isOpen())
    {
    	sf::Event event;
    	while(App.pollEvent(event))
    	{
    		if(event.type == sf::Event::Closed)App.close();
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))pos.x += 0.2;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))pos.x -= 0.2;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))pos.z += 0.2;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))pos.z -= 0.2;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))yaw -= 0.2;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))yaw += 0.2;
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();
    	glTranslatef(0, 0, 0);
    	glRotatef(yaw, 1, 0, 0);
    	r.render(pos);
    	App.display();
    }
    return 0;
}
