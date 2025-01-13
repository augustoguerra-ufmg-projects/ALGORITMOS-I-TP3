#include<bits/stdc++.h>
#include"../include/graph.h"
using namespace std;

graph_c::graph_c(int V):V(V),E(0)
{
	adj.resize(V);
}

void graph_c::add_edge(string&u,string&v,int d)
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
	adj[u_id].emplace_back(v_id,d);
	adj[v_id].emplace_back(u_id,d);
	E++;
}

void graph_c::print()
{
    for(int u=0;u<V;u++)
    {
        cout<<u<<" "<<toString[u]<<":";
        for(auto edge : adj[u])
        {
            cout << "(" <<edge.first<<" "<<toString[edge.first] << ", " << edge.second << ") ";
        }
        cout<<endl;
    }
}
