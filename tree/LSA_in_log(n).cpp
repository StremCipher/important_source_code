vector<ll>tree[100000];
ll depth[100009]; 
ll parent[100009][30]; 
void dfs_2(ll cur, ll prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (ll i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs_2(tree[cur][i], cur); 
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