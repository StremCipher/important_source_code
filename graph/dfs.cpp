void dfs(int start_node) 
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
