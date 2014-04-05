// tsalesman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Line.h"

sf::Font fontTNR;
const int SCR_HEIGHT = 1024;
const int SCR_WIDTH = 768;


void setNodesPosition(std::vector<Node>& nodes){
	sf::CircleShape haha(SCR_WIDTH/4.,nodes.size());
	std::cout << haha.getPointCount() << std::endl;
	haha.setPosition(SCR_HEIGHT/4.,SCR_WIDTH/4.);

	for(sf::Uint32 i = 0; i < haha.getPointCount(); ++i){
		nodes[i].setXY(haha.getPosition().x + haha.getPoint(i).x,haha.getPosition().y + haha.getPoint(i).y);
		std::cout << nodes[i].getX() << "---" << nodes[i].getY() << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N = 10;

	std::vector<Node> nodes(N);
	setNodesPosition(nodes);
	sf::RenderWindow window(sf::VideoMode(SCR_HEIGHT,SCR_WIDTH), "Travelling Salesman");
	window.clear(sf::Color::White);
	fontTNR.loadFromFile("Resource/Font/TIMES.TTF");

	Line l[10][10];
	for(int i = 0; i < N; ++i){
		for(int j = i+1; j < N; ++j){
			l[i][j].create(nodes[i],nodes[j]);
			l[i][j].setCost(10);
			l[i][j].getCost();
			l[i][j].putOnWindow(window);
		}
	}
	
	
	for(int i = 0; i < N; i++){
		nodes[i].setId(i+1);
		printf("%f %f\n",nodes[i].getX(),nodes[i].getY());
		nodes[i].putOnWindow(window);
	}
	window.display();
	while(1);
	return 0;
}

