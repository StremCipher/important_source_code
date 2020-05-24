void dfs(int start_node) //this is traverse top to bottom order
{ 
    vector<bool> visited(100009, false); 
    stack<int> stack; 
    stack.push(start_node); 
    while (!stack.empty()) 
    { 
        int parent_node = stack.top(); 
        stack.pop(); 
        if (!visited[parent_node]) 
            visited[parent_node] = true,cout<<parent_node<<" "; 
        for (auto i = tree[parent_node].begin(); i != tree[parent_node].end(); ++i) 
            if (!visited[*i]) 
                stack.push(*i); 
    } 
    cout<<endl;
}  
void dfs(int start)// this will traverse bottom to top order
{
    vis[start]=1;
    for(int i=0;i<tree[start].size();i++)
    {
        if(vis[tree[start][i]]==0)
        {
            vis[tree[start][i]]=1;
            parent[tree[start][i]]=start;
            dfs(tree[start][i]);
        }
    }
   cout<<start<<" ";
}
