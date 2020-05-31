/*  CREATED BY
    STREAM_CIPHER
    30-may-2020
*/
#include<bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<"="<<(a)<<"\n"
const double pi = acos(-1.0);
typedef long long int ll;
vector<int>tree[300000];
int node_value[300000];
int parent[300000][30];
int depth[300000];
int best,level=20;
//this is for finding parent and depth
void dfs_0(ll cur, ll prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (ll i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs_0(tree[cur][i], cur); 
    } 
} 
void precomputeSparseMatrix(ll n) 
{ 
    for (ll i=1; i<level; i++) 
    { 
        for (ll node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        }
    } 
}
ll lca(ll u, ll v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    ll diff = depth[v] - depth[u]; 
    for (ll i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
    if (u == v) 
        return u; 
    for (ll i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int t;
        cin>>t;
        while(t--)
        {
            clear();
            int n,q;
            cin>>n>>q;
            for(int i=1;i<=n;i++)
                cin>>node_value[i];
            for(int i=0;i<n-1;i++)
            {
                int u,v;
                cin>>u>>v;
                // u--,v--;
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
            memset(parent,-1,sizeof parent);
            dfs_0(1,0);
            precomputeSparseMatrix(n);
            // cout<<parent[3][0]<<endl;
            // cout<<level[5]<<endl;
            while(q--)
            {
                int u,v;
                cin>>u>>v;
                // u--,v--;
                // cout<<node_value[u]<<endl;
                int common=lca(u,v);//finding lca of u,v
                
            }
        }
}