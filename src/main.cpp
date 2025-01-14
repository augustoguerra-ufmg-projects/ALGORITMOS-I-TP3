#include"../include/graph.h"
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
	
	// graph_c G(n);
	matrix_graph_c M(n);

	string u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>d;
		// G.add_edge(u,v,d);
		M.add_edge(u,v,d);
	}
	
	switch(alg_num)
	{
		case 'b':
			TSP_brute_force(M);
		break;
		case 'd':
			cout<<"Algoritmo de programacao dinamica\n";
		break;
		case 'g':
			cout<<"Algoritmo guloso\n";
		break;
		default:
			cout<<"Natureza do algoritmo invalida\n";
	}	

	// G.print();

	cout<<"\n\n\n\n";

	M.print();

	return(0);
}
