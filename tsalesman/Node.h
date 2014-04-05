#pragma once
#include <math.h>
const sf::Color SF_BLACK = sf::Color(0,0,0);
const sf::Color SF_WHITE = sf::Color(255,255,255);
const double PI = acos(-1.);
extern sf::Font fontTNR;

class Node{
private:
	int id;
	float x;
	float y;
	sf::CircleShape shape;
	sf::Text text;

public:
	Node();
	Node(int id,float _x,float _y);
	int getId();
	void setId(int n);
	
	float getX();
	void setX(float n);
	float getY();
	void setY(float n);
	float getXY();
	void setXY(float _x,float _y);

	void setSize(float r);
	void setText(std::string text);
	void initProperties();

	void setDrawPosition(float _x,float _y);
	void putOnWindow(sf::RenderWindow &window);

};
