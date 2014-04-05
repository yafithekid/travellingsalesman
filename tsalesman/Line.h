#pragma once
#include "Node.h"
#include <math.h>

class Line{
private:
	float x;
	float y;
	float rotAngle;
	float length;
	int cost;
	sf::RectangleShape rect;
	sf::Text text;

public:
	void create(float xStart,float yStart,float xEnd,float yEnd);
	void create(Node start,Node end);
	void setColor(sf::Color newColor);
	void setCost(int newCost);

	int getCost() const;

	static float euclidean(Node start,Node end);
	static float euclidean(float xStart,float yStart,float xEnd,float yEnd);
	void putOnWindow(sf::RenderWindow &window);
	void initProperties();
};
