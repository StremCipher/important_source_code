void bfs(int start_node) 
{
    bool vis[100000]={false};
    queue<int>q;
    q.push(start_node);
    vis[start_node] = true;
    while(!q.empty())     
    {
        int parent_node=q.front();
        q.pop();
        for(auto i:graph[parent_node])
        {
            if(!vis[i])
            {         
                 q.push(i);
                 vis[i]=1;
                 cout<<i<<" ";
            }
        }
    }
}