#include "stdafx.h"
#include "Node.h"

Node::Node(){
	this->setX(0);
	this->setY(0);
	this->setId(-1);
	this->initProperties();
}

Node::Node(int id,float _x,float _y){
	this->setId(id);
	this->setX(_x);
	this->setY(_y);
	this->initProperties();
}

int Node::getId(){
	return this->id;
}

void Node::setId(int n){
	this->id = n;
}

float Node::getX(){
	return this->x;
}

void Node::setX(float n){
	this->x = n;
}

float Node::getY(){
	return this->y;
}

void Node::setY(float n){
	this->y = n;
}

void Node::setXY(float _x,float _y){
	this->setX(_x);
	this->setY(_y);
}

void Node::setSize(float _r){
	this->shape.setRadius(_r);
	this->text.setCharacterSize(_r);
}

void Node::setText(std::string text){
	this->text.setString(text);
}

void Node::setDrawPosition(float _x,float _y){
	this->shape.setPosition(_x - this->shape.getRadius(),_y - this->shape.getRadius());
	this->text.setPosition(_x - this->text.getCharacterSize()/2.,_y - this->text.getCharacterSize()/2.);
}

void Node::putOnWindow(sf::RenderWindow &window){
	char mat[10]; sprintf_s<10>(mat,"%d",this->id);
	this->setText(mat);
	this->setDrawPosition(this->x,this->y);
	window.draw(this->shape);
	window.draw(this->text);
}

void Node::initProperties(){
	this->shape.setFillColor(SF_WHITE);
	this->shape.setOutlineThickness(1);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setRadius(20);

	this->text.setColor(SF_BLACK);
	this->text.setFont(fontTNR);
	this->text.setCharacterSize(this->shape.getRadius());
}