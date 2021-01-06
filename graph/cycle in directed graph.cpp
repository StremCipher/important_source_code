/*  CREATED BY
    STREAM_CIPHER
    23-june-2020
*/
// using simple dfs
// keep track of three types of node white=unvisted
                                  // grey=partially visited
                                  // black=completely visited(means all its neighbaring node are visited)
// if we found white and grey vertex same time then there is a cycle 
// we can print cycle using parent array
// this code is still need improvement
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
set<int>graph[mx];
int parent[mx];
int vis[mx];
vector<int>cycle;
bool cycle_present=false;
int is_cycle(int start_node)
{
    int p=start_node;
    vis[p]=0;
    for(auto i:graph[p])
    {
        if(vis[i]==-1)
        {
        	parent[i]=p;
            is_cycle(i);
        }
        else
        {
            if(vis[i]==0)
            {
            	cycle.clear();
                cycle_present=true;
                cycle.push_back(p);
                int p1=p;
                while(1)
                {
                	p1=parent[p1];
                	cycle.push_back(p1);
                	if(p1==i)
                	{
                		break;
                	}
                }
            }
        }
    }
    vis[p]=1;
}
int vis1[mx];
int cycle1;
int is_cycle1(int start_node)
{
    int p=start_node;
    vis1[p]=0;
    for(auto i:graph[p])
    {
        if(vis1[i]==-1)
        {
            is_cycle1(i);
        }
        else
        {
            if(vis1[i]==0)
            {
            	cycle1++;
            }
        }
    }
    vis1[p]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[u].insert(v);
        }
        //graph may or may not connected
        //dtecting any cycle if present in directed graph and print it
        for(int i=0;i<n;i++)
             is_cycle(i);
        //only cheaking is any cycle present or not in graph
         for(int i=0;i<n;i++)
            is_cycle1(i);
}