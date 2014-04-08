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
	int cost2;
	sf::RectangleShape rect;
	sf::Text text;
	sf::Text text2;

public:
	void create(float xStart,float yStart,float xEnd,float yEnd);
	void create(Node start,Node end);
	void setColor(sf::Color newColor);
	void setAltColor(sf::Color newColor);
	void setCost(int newCost);
	void setAltCost(int newCost);

	int getCost() const;
	int getAltCost() const;

	static float euclidean(Node start,Node end);
	static float euclidean(float xStart,float yStart,float xEnd,float yEnd);
	void putOnWindow(sf::RenderWindow &window);
	void initProperties();
};
