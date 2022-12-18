#include<bits/stdc++.h>
using namespace std;

void topoSort(int src , unordered_map<int,list<int>> &adjList ,stack<int> &topoSorted, vector<int> &visited )
{
    visited[src] = 1;
    
    for(auto neighbour : adjList[src]){
        if(!visited[neighbour]){
            topoSort(neighbour,adjList,topoSorted,visited);
        }
    }
    topoSorted.push(src);
}

void dfs(int node , unordered_map<int,list<int>> &revAdjList , vector<int> &vis,
        vector<int> &ans){
    vis[node] = 1 ;
    for(auto neighbour : revAdjList[node]){
        if(!vis[neighbour]){
            dfs(neighbour,revAdjList,vis,ans);
        }
    }
//     ans.push_back(node);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adjList;
    //adjacency list for unweighted directed graph
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        
        adjList[u].push_back(v);
    }
    
    vector<int> visited(v,0);
    stack<int> topoSorted;
    
    for(int i=0 ;i<v;i++){
         if(!visited[i])
         {
             topoSort(i,adjList,topoSorted,visited);
         }
        
}
        
    
    vector<int> topological;
    while(!topoSorted.empty()){
        topological.push_back(topoSorted.top());
        topoSorted.pop();
    }

    unordered_map<int,list<int>> revAdjList;
    for (int i =0 ; i<v ;i++){
        for(auto nbr : adjList[i]){
            revAdjList[nbr].push_back(i);
        }
    }
    
    vector<int> vis(v,0);
    vector<vector<int>> result;
    int count = 0;
//     for(auto top : topological){
//         cout<<top<<"->";
//     }cout<<endl;
    for(auto top : topological){
        vector<int> temp ;
        if(!vis[top]){
            count++;
            dfs(top,revAdjList,vis,temp);
//             for(auto it : vis){
//                 cout<<it<<" ";
//             }cout<<endl;
        }
        result.push_back(temp);
    }
    
    return count;
}
