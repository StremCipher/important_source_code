/*  CREATED BY
    STREAM_CIPHER
    05-sep-2020
*/
//dijkastra single source shortest path algorithm
#include<bits/stdc++.h>
using namespace std;
void __print(long long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long int
#define double long double
#define fix_precision(n) cout<<fixed<<setprecision(n)
#define all(a) a.begin(),a.end()
const double pi=acos(-1.0);
int inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int mx=5*1000000;//5*64M bit ->5*8M byte ->40MB size for long long int (64 bit)
vector<int>g[mx];
map<pair<int,int>,int>weight;
bool vis[mx];
int dis[mx];
int parent[mx];
void dijkastra(int start)
{
    memset(dis,inf,sizeof dis);
    dis[start]=0;
    multiset<int>q;
    q.insert(start);
    while(!q.empty())
    {
        int node=*q.begin();
        q.erase(q.find(node));
        if(vis[node])
            continue;
        vis[node]=1;
        for(auto i:g[node])
        {
            if(dis[i]>(dis[node]+weight[{node,i}]))
            {
                dis[i]=dis[node]+weight[{node,i}];
                q.insert(i);
                parent[i]=node;
            }
        }
    }
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
            weight[{u,v}]=w;
            weight[{v,u}]=w;
        }
        int start_node=0;
        parent[start_node]=-1;
        dijkastra(start_node);
        //shortest distance of each node from start_node
        for(int i=0;i<n;i++)
            cout<<dis[i]<<" ";
        cout<<endl;
        //print shortest path from start to b
        for(int i=0;i<n;i++)
            cout<<parent[i]<<" ";
        cout<<endl;
        //printing shortest path from b to start_node
        int b=4;
        b--;
        while(b!=-1)
            cout<<b+1<<" ",b=parent[b];
}