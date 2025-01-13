#include"../include/graph.h"
using namespace std;

int main()
{	
	char alg_num;
	int n,m,d;

	cin>>alg_num;
	cin>>n>>m;
	
	graph_c G(n);

	string u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>d;
		G.add_edge(u,v,d);
	}

	G.print();
	cout<<alg_num<<"\n";

	return(0);
}
