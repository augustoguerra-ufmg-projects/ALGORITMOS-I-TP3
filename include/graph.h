#ifndef GRAPH_H
#define GRAPH_H
#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

class graph_c
{
	public:
		int V,E;
		unordered_map<string,int>toInt;
		unordered_map<int,string>toString;

		vector<vector<pair<int,int>>>adj;// cada aresta tem uma distancia d > 0
	
		graph_c(int V);
		~graph_c(){}

		void add_edge(string&u,string&v,int d);
		void print();
};

#endif
