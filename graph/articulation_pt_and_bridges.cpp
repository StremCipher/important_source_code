/*  CREATED BY
    STREAM_CIPHER
    05-sep-2020
*/
//finding articulation point and bridges in an graph in nlog(n) time for more detail go to 
//presonal notes or just google;
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
int parent[mx];
int dfs_order[mx],dfs_lowest[mx];
set<int>cut_vertex;
set<pair<int,int>>bridges;
bool vis[mx];
int order=0;
void dfs(int start)
{
    dfs_order[start]=++order;
    dfs_lowest[start]=dfs_order[start];
    vis[start]=1;
    for(auto i:g[start])
    {
        if(!vis[i])
        {
            parent[i]=start;
            dfs(i);
            dfs_lowest[start]=min(dfs_lowest[i],dfs_lowest[start]);
            if(dfs_lowest[i]>=dfs_order[start]&&parent[start]!=-1)//condition for cut vertex
                                                                  //it means there is an back 
                                                                  //edge from any node of subtree
                                                                  //of i to any ancestor of start(excluding start)
                cut_vertex.insert(start);
            if(dfs_lowest[i]>dfs_order[start])//condition for bridge
                                              //it means there is an back 
                                              //edge from any node of subtree
                                              //of i to any ancestor of start including(start)
                bridges.insert({i,start});
        }
        else
        {
            if(i!=parent[start])
                dfs_lowest[start]=min(dfs_lowest[i],dfs_lowest[start]);
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
            int u,v;
            cin>>u>>v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        parent[0]=-1;
        dfs(0);
        if(g[0].size()>1)//checking for root node seperataly
            cut_vertex.insert(0);
        cout<<"cut_vertex are\n";
        for(auto i:cut_vertex)
            cout<<i+1<<",";
        cout<<endl;
        cout<<"bridges are\n";
        for(auto [x,y]:bridges)
            cout<<"["<<x+1<<","<<y+1<<"],";
}