#include<bits/stdc++.h>
#include"../include/matrix.h"
using namespace std;

matrix_graph_c::matrix_graph_c(int V):V(V),E(0)
{
	matrix_adj.resize(V,vector<int>(V,0)); 
}

void matrix_graph_c::add_edge(string&u,string&v,int d)
{
	if(toInt.find(u)==toInt.end())
	{
		int id=static_cast<int>(toInt.size());
		toInt[u]=id;
		toString[id]=u;
	}
	if(toInt.find(v)==toInt.end())
	{
		int id=static_cast<int>(toInt.size());
        	toInt[v]=id;
        	toString[id]=v;
	}
	int u_id=toInt[u];
	int v_id=toInt[v];
	matrix_adj[u_id][v_id]=d;
	matrix_adj[v_id][u_id]=d;
	E++;
}

void matrix_graph_c::print()
{
	cout<<"     ";
	for(int i=0;i<V;i++)
		cout<<i<<"    ";
	cout<<"\n";

	for(int i=0;i<V;i++)
		cout<<"----";
	cout<<"\n";

	for(int i=0;i<V;i++)
	{
		cout<<i<<" | ";
		
		for(int j=0;j<V;j++)
			cout<<matrix_adj[i][j]<<"  ";

		cout<<"\n";
	}

	for(auto& pair:toString)
	{
        	cout << pair.first << " : " << pair.second << "\n";
    	}
}
