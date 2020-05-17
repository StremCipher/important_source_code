 void bfs(int start_node) 
    {
        bool vis[100000]={false};
        queue <int> q;
        q.push(s);
        vis[ s ] = true;
        while(!q.empty()) 
            
        {
            int parent_node = q.front();
            q.pop();
            for(int i = 0;i < v[ parent_node ].size() ; i++)
            {
                if(vis[ v[ parent_node ][ i ] ] == false)
                {         
                     q.push(v[ parent_node ][ i ]);
                     cout<<v[parent_node][i]<<" ";
                     vis[ v[ parent_node ][ i ] ] = true;
                }
            }
        }
    }