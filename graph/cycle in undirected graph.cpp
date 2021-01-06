/*  CREATED BY
    STREAM_CIPHER
    23-june-2020
*/
// do a simple dfs if a vertex appers twice and it is not the parent of current node then we found a cycle 
// now print cycle using parent array
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
vector<int>graph[300000];
int parent[300000];
vector<int>cycle_1;
int visited[300000]={false}; 
bool is_cycle(int start_node)
{
    stack<int> s1;
    s1.push(start_node); 
    parent[start_node]=-1;
    stack<int> cycle; 
    while (!s1.empty()) 
    { 
        int parent_node = s1.top(); 
        s1.pop(); 
        visited[parent_node] = true;
        for (auto i:graph[parent_node])
        {
            if (!visited[i]) 
            {
                parent[i]=parent_node;
                s1.push(i); 
            }
            else
            {   
                if(i!=parent[parent_node])
                {
                    int p=parent_node;
                    cycle_1.push_back(p);
                    while(1)
                    {
                        p=parent[p];
                        cycle_1.push_back(p);
                        if(p==i)
                            break;
                    }
                    return true;
                }
            }
        } 
    }
    return false;
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
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(is_cycle(i))
                {
                    // printing cycle;
                    for(auto i:cycle_1)
                        cout<<i<<" ";
                    break;
                }
            }
        }
}