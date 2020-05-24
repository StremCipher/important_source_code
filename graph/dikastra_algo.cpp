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
int parent[300009];
bool vis[300009];
int inf=0x3f3f3f3f;
void digkastra(int start_node)
{
    // cout<<node<<" ";
  memset(dis,0x3f3f3f3f,sizeof dis);
  memset(vis,false,sizeof vis);
  dis[start_node]=0;
  multiset<int>q;
  q.insert(start_node);
  while(!q.empty())
  {
    auto temp=*q.begin();
    q.erase(q.begin());
    int node;
    node=temp; 
    if(vis[node]) 
      continue;
    vis[node]=true;
    for(int i=0;i<graph[node].size();i++)
    {
       if(dis[graph[node][i]]>(dis[node]+weight[{node,graph[node][i]}]))
       {
            dis[graph[node][i]]=dis[node]+weight[{node,graph[node][i]}];
            q.insert(graph[node][i]);
            parent[graph[node][i]]=node;
       }    
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
    digkastra(start_node);
    for(int i=0;i<node;i++)
      cout<<dis[i]<<" ";
    cout<<endl;
    //printing shortest path between node 0 ans b (from b to 0)
    int b=3;
    while(parent[b]!=0)
        {
      cout<<b<<" ";
      b=parent[b];
        }
}