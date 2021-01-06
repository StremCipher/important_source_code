/*  CREATED BY
    STREAM_CIPHER
    05-sep-2020
*/
//MST(minimum spanning tree) using DSU (Kruskal's algorithm)
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define debug1(a) cout<<#a<<"="<<(a)<<"\n"
#define debug2(a,b) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<"\n"
#define debug3(a,b,c) cout<<#a<<"="<<(a)<<","<<#b<<"="<<(b)<<","<<#c<<"="<<(c)<<"\n"
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
int parent[mx];
int size1[mx];
vector<int>g[mx];
vector<int>mst[mx];
vector<pair<int,pair<int,int>>>edge;
bool vis[mx];
void dfs(int start)
{
    vis[start]=1;
    cout<<start+1<<" ";
    for(auto i:mst[start])
        if(!vis[i])
            dfs(i);
}
int find(int x)
{
    while(x!=parent[x])
        x=parent[x];
    return x;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
void join(int x,int y)//it join the two set haveing element x and y respectively
{
    x=find(x);
    y=find(y);
    if(size1[x]<size1[y])
        swap(x,y);
    size1[x]+=size1[y];
    parent[y]=x;//connect representative of smaller set to larger set always
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
            edge.push_back({w,{u,v}});
        }
        sort(all(edge));
        reverse(all(edge));
        for(int i=0;i<n;i++)
            size1[i]=1,parent[i]=i;
        int start,wt=0;
        for(auto [w,nodes]:edge)
        {
            if(same(nodes.first,nodes.second))
                continue;
            start=nodes.first;
            mst[nodes.first].push_back(nodes.second);
            mst[nodes.second].push_back(nodes.first);
            join(nodes.first,nodes.second);
            wt+=w;
        }
        //print the minimum weught
        cout<<wt<<endl;
        //print mst
        // dfs(start);
}