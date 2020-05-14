
/*
  //representation of graph using adjacency matrix
  //
*/
#include<bits/stdc++.h>
using namespace std;


bool adjacency_mat[100][100];
void initialize()
{
for(int i=0;i<100;i++)
for(int j=0;<100;j++)
adjacency_mat[i][j]=false;

}
int main() 
{
     initialize();
	int vertex,edge,x,y;
	cin>>vertex>>edge;
	for(int i=0;i<edge;i++)
	{
	     cin>>x>>y;
	     adjacency_mat[x][y]=true;
	     adjacency_mat[y][x]=true;//if graph is undirected;
	}
}
