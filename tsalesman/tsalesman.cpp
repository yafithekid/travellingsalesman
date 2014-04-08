// tsalesman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Line.h"
#include "Graph.h"
#include <queue>
#include <time.h>

sf::Font fontTNR;
const int SCR_HEIGHT = 1024;
const int SCR_WIDTH = 768;

int nBangkit = 0;

void setNodesPosition(std::vector<Node>& nodes){
	sf::CircleShape haha(SCR_WIDTH/2.5,nodes.size());
	std::cout << haha.getPointCount() << std::endl;
	haha.setPosition(SCR_HEIGHT/12.,SCR_WIDTH/12.);

	for(sf::Uint32 i = 0; i < haha.getPointCount(); ++i){
		nodes[i].setXY(haha.getPosition().x + haha.getPoint(i).x,haha.getPosition().y + haha.getPoint(i).y);
		std::cout << nodes[i].getX() << "---" << nodes[i].getY() << std::endl;
	}
}

QElement doBFS(QElement root){
	std::priority_queue<QElement> pq;
	root.flipCostSign();
	pq.push(root);

	while (!pq.empty()){
		QElement top = pq.top(); top.flipCostSign(); pq.pop();
		nBangkit++;
		top.printMatrix();
		if (top.getVisitedNode().size() == root.getNodeCount() + 1){
			nBangkit += pq.size();
			return top;
		}

		std::vector<QElement> child = top.expandElement();
		for(sf::Uint32 i = 0; i < child.size(); ++i){
			child[i].flipCostSign();
			pq.push(child[i]);
		}
	}
}

bool used[25][25];

void setUsedEdges(std::vector<int> path){
	for(int i = 0; i + 1 < (int) path.size(); ++i){
		used[path[i]][path[i+1]] = true;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	QElement root;
	printf("masukkan banyak node = ");  scanf("%d",&N);
	root.setNodeCount(N);
	root.readData();
	root.insertVisited(0);

	std::vector<Node> nodes(N);
	setNodesPosition(nodes);
	sf::RenderWindow window(sf::VideoMode(SCR_HEIGHT,SCR_WIDTH), "Travelling Salesman");
	window.clear(sf::Color::White);
	fontTNR.loadFromFile("Resource/Font/TIMES.TTF");
	
	clock_t t0 = clock();
	QElement result = doBFS(root);
	clock_t tt = clock();
	printf("tur: "); result.printVisited();
	printf("waktu eksekusi (milisec): %.6lf\n",(double) ((tt-t0) * 1000.0/CLOCKS_PER_SEC));
	printf("total cost : %d\n",result.getCost());
	printf("simpul yang bangkit : %d\n",nBangkit);
	setUsedEdges(result.getVisitedNode());
	
	printf("\n");

	Line l[20][20];
	for(int i = 0; i < N; ++i){
		for(int j = i+1; j < N; ++j){
			l[i][j].create(nodes[i],nodes[j]);
			l[i][j].setCost(root.getEdge(i,j));
			l[i][j].setAltCost(root.getEdge(j,i));
			if (used[i][j]){
				l[i][j].setColor(sf::Color::Red);
			} else if (used[j][i]){
				l[i][j].setAltColor(sf::Color::Red);
			}
			l[i][j].putOnWindow(window);
		}
	}
	
	
	for(int i = 0; i < N; i++){
		nodes[i].setId(i+1);
		nodes[i].putOnWindow(window);
	}
	window.display();
	while(1);
	return 0;
}

