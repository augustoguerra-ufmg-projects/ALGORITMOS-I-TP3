#include<bits/stdc++.h>
#include"../include/matrix.h"
using namespace std;

void exhaustive_search(vector<int>&vertices,int index,matrix_graph_c&G,int& min, vector<int>& min_circuit)
{
	// permutacao completa deve ser testada como solucao
	if(index==static_cast<int>(vertices.size()-1))
	{
		// procesa essa permutacao para ver se o custo e melhor
		bool valid_circuit=true;
		int predc=0; // vertice predecessor no circuito comeca em 0 e checa se ha aresta ligando
		int sum=0;
		for(size_t i=0;i<vertices.size();i++)// esse meu vetor representa um caminho
		{
			int v=vertices[i];
			if(G.matrix_adj[predc][v]==0)
			{
				valid_circuit=false;
				break;
			}
			sum+=G.matrix_adj[predc][v];
			predc=v;
		}
		if(valid_circuit and G.matrix_adj[predc][0]!=0)
			sum+=G.matrix_adj[predc][0];
		else valid_circuit=false;

		if(valid_circuit and sum<min)
		{
			min=sum;
			min_circuit=vertices;	
		}
		return;
	}
	
	// gera permutacao recursivamente
	for(size_t i=index;i<vertices.size();i++)
	{
		swap(vertices[index],vertices[i]);
		exhaustive_search(vertices,index+1,G,min,min_circuit);
		swap(vertices[index],vertices[i]);
	}
}

void TSP_brute_force(matrix_graph_c&G)
{
	vector<int>vertices;
	int min=INT_MAX;
	vector<int>min_circuit;

	for(int i=1;i<G.V;i++)
		vertices.push_back(i);
	
	exhaustive_search(vertices,0,G,min,min_circuit);

	if(min!=INT_MAX)
	{
		cout<<min<<"\n";

		cout<<G.toString[0]<<" ";
		for(int v:min_circuit)
			cout<<G.toString[v]<<" ";
		cout<<"\n";		
	}
	else cout<<"eita\n"; // debugando
}
