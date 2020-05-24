/*  CREATED BY
    STREAM_CIPHER
    22-may-2020
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int>graph[300009];
map<pair<int,int>,int>weight;
vector<pair<int,int>>edges;
int node,edge;
int dis[300009];
int inf=0x3f3f3f3f;
bool neg_cycle=false;
void belford(int start_node)
{
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[start_node]=0;
	for(int i=0;i<node;i++)
	{
		for(int j=0;j<edge;j++)
		{
			int u=edges[j].first,v=edges[j].second;
			if(dis[u]!=inf&&dis[u]+weight[{u,v}]<dis[v])
				dis[v]=dis[u]+weight[{u,v}];
		}
	}
	//cheking for -ve cycle
	for(int j=0;j<edge;j++)
	{
		int u=edges[j].first,v=edges[j].second;
		if(dis[u]!=inf&&dis[u]+weight[{u,v}]<dis[v])
		{
			neg_cycle=true;
			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		cin>>node>>edge;
		for(int i=0;i<edge;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			u--,v--;
			weight[{u,v}]=w;
			graph[u].push_back(v);
			graph[v].push_back(u);
			edges.push_back({u,v});
		}
		int start_node=0;
		belford(start_node);
		if(!neg_cycle)
		{
			for(int i=0;i<node;i++)
				cout<<dis[i]<<" ";
			cout<<endl;
		}
		else
			cout<<"neg_cycle detected\n";
}