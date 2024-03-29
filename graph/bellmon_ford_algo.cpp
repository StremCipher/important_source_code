/*  CREATED BY
    STREAM_CIPHER
    22-may-2020
*/
//single source shortest path if there is -ve edge
//time complexity O(e*v)
//this code still need improvement
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
int32_t main()
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