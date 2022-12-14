//BFS Crude version
/*
Time complexity : O(V+E)
Space complexity : O(V+E)
*/

#include <bits/stdc++.h> 
using namespace std;
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,bool> visited; //visited array
    for(int i =0 ; i < vertex ;i++){
        visited[i] = false;
    }
    vector<int>neighbors[vertex]; //neighbors array
    for(int i =0 ; i< edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }
    for(int i =0 ;i<vertex;i++){
       sort(neighbors[i].begin(),neighbors[i].end());
    }
    queue<int> q; // queue for bfs implementation
    vector<int> result;
    for(int v = 0;v< vertex;v ++){
      if(!visited[v]){
         q.push(v);
      }
      while(!q.empty()){
        int qFront = q.front();
        if(!visited[qFront]){
            result.push_back(qFront);
            visited[qFront] = true;
            q.pop();
            for(int i = 0 ;i < neighbors[qFront].size();i++){
                q.push(neighbors[qFront][i]);
            }
         }else{
            q.pop();
        }
       }
    }
    return result;
}
