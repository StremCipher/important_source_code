/*   CREATED BY
       STREAM_CIPHER
       28-03-2020
  */
//this algo is for sortest distance and shortest path from a single node weight of all edge is 1 here
  #include <bits/stdc++.h>
  #include <cstdio>
  #define mx 1e18+7
  using namespace std;
  typedef long long  int ll;
  vector<int>graph[300009];
bool visited[300009];
ll dis[300009];
ll parent[300009];
void shortest_path(int start)
  { 
    // cout<<"A\n";
     //cout<<start<<endl;
     memset(dis,0x3f3f3f3f,sizeof dis);
     memset(visited,false,sizeof visited);
     dis[start]=0;
     multiset<int>p_q;
     p_q.insert(start);
    while(!p_q.empty())
    {
       auto temp=*p_q.begin();
       p_q.erase(p_q.begin());
       int node,wt;
       node=temp; 
       if(visited[node]) 
          continue;
       visited[node]=true;

       for(int i=0;i<graph[node].size();i++)
       {
           if(dis[graph[node][i]]>(dis[node]+1))
           {
                //cout<<graph[node][i]<<" ";
                dis[graph[node][i]]=dis[node]+1;
                p_q.insert(graph[node][i]);
                parent[graph[node][i]]=node;
                // cout<<graph[node][i]<<" "<<node<<endl;
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
        int node,edge;
        cin>>node>>edge;
        for(int i=1;i<edge;i++)
        {
          int x,y;
          cin>>x>>y;
          graph[x].push_back(y);
          graph[y].push_back(x);
        }
        shortest_path(1);//this will find shortest distance from node 1 to all other node
        shortest distance of all node from node 1
          for(int i=1;i<=node;i++)
            cout<<dis[i]<<endl;
        printing shortest path between 1 and any node say b=5;
        while(parent[b]!=0)
        {
          cout<<b<<" ";
          b=parent[b];
        }
   }      