
/*
  //representation of graph using adjacency_lis
*/
#include<bits/stdc++.h>
using namespace std;


int main() 
{
     
	int vertex,edge,x,y;
	cin>>vertex>>edge;
	vector<int> adj[vertex+1];
	for(int i=0;i<edge;i++)
	{
	     cin>>x>>y;
	     adj[x].push_back(y);
	}
	//cout<<adj[5]
	for(int i=1;i<=vertex;i++)
	{
	     if(adj[i].size()>0)
	     cout<<i<<"=";
	     for(int j=0;j<adj[i].size();j++)
	     {
	          if(j == adj[i].size() - 1)
                    cout << adj[i][j];
            else
                cout << adj[i][j] <<",";
	     }
	     cout<<"\n";
	}
//to clear vector space;
  for(int i=0;i<vertex+1;i++)
   {
     adj[i].clear();
   }
	
}
