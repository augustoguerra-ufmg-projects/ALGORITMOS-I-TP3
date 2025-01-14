#ifndef MATRIX_H
#define MATRIX_H
#include<bits/stdc++.h>
using namespace std;

class matrix_graph_c
{
	public:
		int V,E;
		unordered_map<string,int>toInt;
		unordered_map<int,string>toString;

		vector<vector<int>>matrix_adj;
		
		matrix_graph_c(int V);
		~matrix_graph_c(){}

		void add_edge(string&u,string&v,int d);
		void print();
};

#endif
