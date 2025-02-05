//==========================================================================//
//	autor:	augusto guerra de lima					    //
//	arquivo	: main.cpp 						    //
//	descricao : processa a entrada para o tp3			    //
//==========================================================================//

#include"../include/matrix.h"
#include"../include/alg.h"
using namespace std;


/*
 _____ ____ _____ 
|_   _|  _ \___ / 
  | | | |_) ||_ 
  | | |  __/___) |
  |_| |_|  |____/ 

 */

int main()
{	
	char alg_num;
	int n,m,d;

	cin>>alg_num;
	cin>>n>>m;
	
	matrix_graph_c M(n);

	string u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>d;
		M.add_edge(u,v,d);
	}
	
	switch(alg_num)
	{
		case 'b':
			TSP_brute_force(M);
		break;
		case 'd':
			TSP_dynamic_programming(M);
		break;
		case 'g':
			TSP_greedy(M);
		break;
		default:
			cout<<"Natureza do algoritmo invalida\n";
	}	

	return(0);
}
