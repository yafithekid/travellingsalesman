#include "stdafx.h"
#include "Graph.h"
#define MAXSIZE 20

QElement::QElement()  {
	r = 0;
	for(int i = 0; i < MAXSIZE; ++i){
		mat[i].resize(MAXSIZE);
	}
}
int QElement::getCost() const{
	return this->r;
}
void QElement::setCost(int val){
	this->r = val;
}

void QElement::setNodeCount(int n){
	this->N = n;
}

int QElement::getNodeCount(){
	return this->N;
}

int QElement::getValMinRow(int r){
	int minRes = INF;
	int idxMinRes = -1;
	for(int i = 0; i < getNodeCount(); ++i){
		if (mat[r][i] != INF && mat[r][i] < minRes){
			idxMinRes = i;
			minRes = mat[r][i];
		}
	}
	return minRes;
}

int QElement::getValMinCol(int c){
	int minRes = INF;
	int idxMinRes = -1;
	for(int i = 0; i < getNodeCount(); ++i){
		if (mat[i][c] != INF && mat[i][c] < minRes){
			idxMinRes = i;
			minRes = mat[i][c];
		}
	}
	return minRes;
}

int QElement::reduceRow(int r,int val){
	int retVal = 0;
	for(int j = 0; j < getNodeCount(); ++j){
		if (mat[r][j] != INF){
			retVal += (mat[r][j] - val);
			mat[r][j] -= val;
		}
	}
	return retVal;
}

int QElement::reduceCol(int c,int val){
	int retVal = 0;
	
	for(int i = 0; i < getNodeCount(); i++){
		if (mat[i][c] != INF){
			retVal += (mat[i][c] - val);
			mat[i][c] -= val;
		}
	}
	return retVal;
}

int QElement::reduceMatrix(int u,int v){
	int retVal = 0;
	for(int i = 0; i < getNodeCount(); i++){
		for(int j = 0; j < getNodeCount(); j++){
			if (i == u || j == v) mat[i][j] = INF;
		}
	}
	for(int i = 0; i < getNodeCount(); ++i){
		int vMin = this->getValMinRow(i);
		this->reduceRow(i,vMin);
		if (vMin != INF) retVal += vMin;
	}
	for(int j = 0; j < getNodeCount(); ++j){
		int vMin = this->getValMinCol(j);
		this->reduceCol(j,vMin);
		if (vMin != INF) retVal += vMin;
	}
	return retVal;
}

void QElement::readData(){
	for(int i = 0; i < getNodeCount(); ++i){
		for(int j = 0; j < getNodeCount(); j++){
			scanf("%d",&mat[i][j]);
			if (i == j) mat[i][j] = INF;
		}
	}
}

int QElement::getEdge(int u,int v){
	assert(0 <= u && u < getNodeCount());
	assert(0 <= v && v < getNodeCount());
	return mat[u][v];
}

void QElement::setEdge(int u,int v,int cost){
	assert(0 <= u && u < getNodeCount());
	assert(0 <= v && v < getNodeCount());
	mat[u][v] = cost;
}

bool operator<(const QElement &Q1,const QElement &Q2){
	return Q1.r < Q2.r;
}

bool operator>(const QElement &Q1,const QElement &Q2){
	return Q1.r > Q2.r;
}


std::vector<int> QElement::expandNode(){
	std::vector<bool> already(getNodeCount(),false);
	std::vector<int> retVal;

	for(int i = 0; i < (int) visited.size(); ++i){
		already[visited[i]] = true;
	}
	for(int i = 0; i < getNodeCount(); ++i){
		if (!already[i])
			retVal.push_back(i);
	}
	return retVal;
}

void QElement::insertVisited(int u){
	this->visited.push_back(u);
}

std::vector<QElement> QElement::expandElement(){
	std::vector<int> nodes = this->expandNode();
	std::vector<QElement> retVal;
	if (nodes.size() > 0){
		for(sf::Uint32 i = 0; i < nodes.size(); ++i){
			int vNow = nodes[i];
			QElement next = *this;
			int lastCost = this->getCost(),edgeCost = this->getEdge(this->getLastNode(),vNow),matrixCost = next.reduceMatrix(this->getLastNode(),vNow);
			next.setCost(lastCost + edgeCost + matrixCost);
			next.insertVisited(vNow);
			retVal.push_back(next);
		}
	} else {
		QElement ret = *this;
		ret.insertVisited(0);
		retVal.push_back(ret);
	}
	return retVal;
}

int QElement::getLastNode() const{
	return this->visited.back();
}
std::vector<int> QElement::getVisitedNode() const{
	return this->visited;
}
void QElement::flipCostSign(){
	this->setCost(-this->getCost());
}

void QElement::printMatrix(){
	for(int i = 0; i < this->getNodeCount(); ++i){
		for(int j = 0; j < this->getNodeCount(); ++j){
			printf("%3d ",this->mat[i][j] == INF?-1:this->mat[i][j]);
		}
		printf("\n");
	}
	printf("mat = "); this->printVisited();
	printf("cost = %d\n",this->getCost());
}
void QElement::printVisited(){
	for(sf::Uint32 i = 0; i < this->getVisitedNode().size(); ++i){
		printf("%d ",this->getVisitedNode()[i] + 1);
	}
	printf("\n");
}
#undef MAXSIZE