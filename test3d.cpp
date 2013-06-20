/*
 * test3d.cpp
 *
 *  Created on: Jan 29, 2013
 *      Author: Technius
 */
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include "Vec3d.h"
#include "Rect3d.h"
#include <string>
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
    Vec3d pos(0, 0, -3);
    App.setFramerateLimit(60);
    float yaw = 0;

    Rect3d r(Vec3d(0, 0, 0), Vec3d(1, 1, 1));
	sf::Text text;
	sf::Font font;
	bool l = font.loadFromFile("arial.ttf");
	text.setCharacterSize(30);
    while(App.isOpen())
    {
    	sf::Event event;
    	while(App.pollEvent(event))
    	{
    		if(event.type == sf::Event::Closed)App.close();
    	}
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))pos.x += 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))pos.x -= 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))pos.z += 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))pos.z -= 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))yaw == 0 ? yaw = 359 : yaw -= 1;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))yaw == 359 ? yaw = 0 : yaw += 1;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))pos.y += 0.01;
    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))pos.y -= 0.01;
		//Pitch
		/*
		if(yaw == 0)pos.z += 0.01;
		else
		{
			pos.z += 0.01*sin(yaw);
			pos.x += 0.01*cos(yaw);
		}*/
    	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();
    	glRotatef(yaw, 1, 0, 0);
    	r.render(pos);
    	if(l)
    	{
        	stringstream ss;
        	ss << "X: " << pos.x << " Y:" << pos.y << " Z:" << pos.z;
        	text.setString(ss.str());
        	App.pushGLStates();
        	App.draw(text);
        	App.popGLStates();
    	}
    	App.display();
    }
    return 0;
}
