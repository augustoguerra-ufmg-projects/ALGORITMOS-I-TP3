//
//	autor : augusto guerra de lima
//	arquivo	: alg.cpp
//	descricao : implementa as estrategias de algoritmos utilizados no tp3
//

#include<bits/stdc++.h>
#include"../include/matrix.h"
using namespace std;

//=================================================================================================================
//	Forca bruta
//=================================================================================================================

/*
 *	exhaustive_search : gera permutacoes dos vertices para decidir melhor circuito
 */
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

/*
 *	TSP_brute_force : processa o grafo para uma busca exaustiva e imprime o melhor custo e circuito
 */
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
} // end Forca bruta

//===========================================================================================================
//	Programacao dinamica
//===========================================================================================================

/*
 *	DP : realiza a busca do melhor custo e a construcao do melhor circuito usando memoizacao e bitmasking
 */
int DP(int v,int visited,matrix_graph_c& G,vector<vector<int>>& memo,vector<vector<int>>&circuit)
{
	// caso base computou todos
	if(visited==(1<<G.V)-1)
		return(G.matrix_adj[v][0]==0?INT_MAX:G.matrix_adj[v][0]);
	
	// caso estado ja calculado na matriz de memoizacao
	if(memo[v][visited]!=-1)
		return(memo[v][visited]);
	
	int min=INT_MAX;
	
	// computa funcao objetivo minima naquele estado
	for(int i=0;i<G.V;i++)
		if(!(visited & (1<<i)) && G.matrix_adj[v][i]!=0)
		{
			int cost=G.matrix_adj[v][i]+DP(i,visited | (1<<i),G,memo,circuit);
			if(cost<min)
			{
				min=cost;
				circuit[v][visited]=i;
			}
		}

	// salva na matriz de memoizacao
	return(memo[v][visited]=min);	
}

/*
 * 	TSP_dynamic_programming	: processa grafo para uma busca de programação dinamica
 */
void TSP_dynamic_programming(matrix_graph_c& G)
{
	vector<vector<int>>memo(G.V,vector<int>(1<<G.V,-1)); // a memo requer Vx2^V de espaco armazenado
	vector<vector<int>>circuit(G.V,vector<int>(1<<G.V,-1));

	int min=DP(0,1,G,memo,circuit);

	if(min!=INT_MAX)
	{
		cout<<min<<"\n";
		int visited=1;
		int curr=0;
		cout<<G.toString[curr]<<" ";
		while(true)
		{
			curr=circuit[curr][visited];
			if(curr==-1)break;

			visited |=(1<<curr);
			cout<<G.toString[curr]<<" ";
		}
		cout<<"\n";
	}
} // end Programacao dinamica

//==================================================================
//	Guloso
//==================================================================

/*
 * 	naive_local_search : busca local nas vizinhancas do vertice
 */
int naive_local_search(matrix_graph_c&G,vector<int>&min_circuit)
{
	vector<bool>visited(G.V,false);
	int result=0;
	min_circuit.push_back(0);
	visited[0]=true;

	int curr=0;
	for(int i=1;i<G.V;i++)
	{
		int next=-1;
		int min=INT_MAX;
		for(int v=0;v<G.V;v++)
			if(!visited[v] and G.matrix_adj[curr][v]!=0 and G.matrix_adj[curr][v]<min)
			{
				min=G.matrix_adj[curr][v];
				next=v;
			}
		if(next==-1)return(INT_MAX);

		result+=min;
		curr=next;
		min_circuit.push_back(curr);
		visited[curr]=true;
	}
	result+=G.matrix_adj[curr][0];	// preco de voltar a origem
	return(result);
}

/*
 *	TSP_greedy : processa grafo para busca local
 */
void TSP_greedy(matrix_graph_c& G)
{
	vector<int>min_circuit;
	int min=INT_MAX;
	
	min=naive_local_search(G,min_circuit);

	if(min!=INT_MAX)
	{
		cout<<min<<"\n";
		for(int v:min_circuit)
			cout<<G.toString[v]<<" ";
		cout<<"\n";
	}
} // end Guloso
