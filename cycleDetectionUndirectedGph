// Cycle Detection in Undirected Graph

#include<bits/stdc++.h>
using namespace std;

string dfs(int i ,  vector<int> &visited , unordered_map<int,list<int>> &adjList , int parent )
{
  visited[i] = 1;
     for(auto it : adjList[i])
     {
         if(visited[it] == 0 )
         {
             string temp = dfs(it,visited,adjList,i);
             if(temp == "Yes") return "Yes";
         }
         else if(parent != it){
             return "Yes";
         }
     }
    return "No";
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adjList;
    //adjacency list
    for(int i =0 ;i < m ;i ++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    //vistied array
    vector<int> visited (n+1 , 0);
    //parent array;
    
    string result = "No";
    for(int i = 1 ; i<= n; i++)
    { 
        if(!visited[i])
        {
            result = dfs(i,visited,adjList,-1);
        }
        if(result == "Yes") return result;
    }
    
    return result;
}
