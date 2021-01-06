
void dfs(int start_node)//this is traverse top to bottom order
{
    bool vis[20000]={0};
    stack<int>s;
    s.push(start_node);
    while(!s.empty())
    {
        int p=s.top();
        s.pop();
        if(!vis[p])
            cout<<p+1<<" ";
        vis[p]=true;
        for(auto i:graph[p])
        {
            if(!vis[i])
                s.push(i);
        }
    }
}
void dfs(int start)// this will traverse bottom to top order
{
    vis[start]=1;
    for(auto i:graph[start])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
   cout<<start<<" ";
}
