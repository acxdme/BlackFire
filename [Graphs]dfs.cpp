//Depth First Seach


//function to execute dfs logic
void dfs(int i , vector<int> adj[ ] ,unordered_map<int,bool> &visited, 
vector<int> &component){
    
    if(visited[i] == true) return;
    component.push_back(i);
    visited[i]= true;
    
    for(int k = 0 ; k<adj[i].size();k++){
       dfs(adj[i][k],adj,visited,component);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //adjacency matrix
    vector<int> adj[V];
    for(int i=0 ;i < E ;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // initialize visited array
    unordered_map<int,bool> visited;
    for(int i = 0 ; i< V ;i ++){
        visited[i] = false;
    }
    
    // result
    vector<vector<int>> result;
    
    // execute dfs for each non-visited vertex
    for(int i =0 ;i < V ; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adj,visited,component);
            result.push_back(component);
        }
    }
    return result;
}
