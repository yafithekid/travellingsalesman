#include "stdafx.h"
#include "Line.h"

void Line::setColor(sf::Color newColor){
	this->rect.setFillColor(newColor);
	this->text.setColor(newColor);
}

void Line::create(float xStart,float yStart,float xEnd,float yEnd){
	this->x = xStart;
	this->y = yStart;
	this->length = Line::euclidean(xStart,yStart,xEnd,yEnd);
	this->rotAngle = atan2(yEnd - yStart,xEnd - xStart);
	this->initProperties();
}

void Line::create(Node start,Node end){
	this->create(start.getX(),start.getY(),end.getX(),end.getY());
}

void Line::setCost(int newCost){
	this->cost = newCost;
}
float Line::euclidean(float xStart,float yStart,float xEnd,float yEnd){
	float dx = xEnd - xStart;
	float dy = yEnd - yStart;
	return sqrt(dx*dx + dy*dy);
}

float Line::euclidean(Node start,Node end){
	return Line::euclidean(start.getX(),start.getY(),end.getX(),end.getY());
}

void Line::putOnWindow(sf::RenderWindow &window){
	char mat[10]; sprintf_s<10>(mat,"%d",this->cost);
	this->text.setString(mat);
	this->text.setPosition(x + length/2.*cos(rotAngle),y + length/2.*sin(rotAngle));

	this->rect.setPosition(this->x,this->y);
	this->rect.setSize(sf::Vector2f(this->length,1));
	this->rect.setRotation(this->rotAngle*180./PI);
	
	window.draw(this->text);
	window.draw(this->rect);
	
}

void Line::initProperties(){
	this->text.setFont(fontTNR);
	this->text.setCharacterSize(12);
	this->text.setColor(sf::Color::Black);
	rect.setFillColor(sf::Color::Black);
}

int Line::getCost() const {
	return this->cost;
}