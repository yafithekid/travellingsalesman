#pragma once
#include <vector>

class QElement{
#define MAXSIZE 20
private:
	std::vector<int> mat[MAXSIZE];
	std::vector<int> visited;
	int r;
	int N;
	const static int INF = 10000000;

public:
	QElement();
	int getValMinRow(int i);
	int getValMinCol(int i);
	int reduceMatrix(int u,int v);
	int getLastNode() const;
	std::vector<int> getVisitedNode() const;
	int getCost() const;
	void setCost(int val);
	void flipCostSign();

	int getEdge(int u,int v);
	void setEdge(int u,int v,int val);
	void insertVisited(int u);
	
	friend bool operator<(const QElement &Q1,const QElement &Q2);
	friend bool operator>(const QElement &Q1,const QElement &Q2);
	std::vector<int> expandNode();
	std::vector<QElement> expandElement();

	int reduceRow(int r,int val);
	int reduceCol(int c,int val);
	void setNodeCount(int n);
	int getNodeCount();
	void readData();
	void printMatrix();
	void printVisited();
#undef MAXSIZE
};