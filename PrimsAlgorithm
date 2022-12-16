#include <bits/stdc++.h> 
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>> > adjList;
    // adjacency list creation for directed connected weighted graph
    for(auto edge : g){
      int u = (edge.first).first;
      int v = (edge.first).second;
      int w = edge.second;
       
      adjList[u].push_back(make_pair(v,w));
      adjList[v].push_back(make_pair(u,w)); 
    }
    
    
    // key array
    vector<int> key(n+1,INT_MAX);
    //mst array
    vector<int> mst(n+1,0);
    //parent array
    vector<int> parent(n+1,-1);
    
    int src = 1 ;
    key[src]= 0;
    parent[src] = -1;
    for(int i=1 ; i <= n ;i++){
        int mini = INT_MAX;
        int minPos = 1;
        
        for(int v =1 ; v<= n ;v ++){
            if(key[v] < mini && mst[v] == 0 )
            {
               mini = key[v];
               minPos = v; 
            }
          }
//          cout<<minPos<<endl; printing the min position
        //mark mst as true
        mst[minPos] = 1;
        
        for(auto neighbour : adjList[minPos]){
            if( mst[neighbour.first] == 0  &&  neighbour.second < key[neighbour.first]){
                    key[neighbour.first] = neighbour.second;
                    parent[neighbour.first] = minPos;
//                 mst[neighbour.first] = 1; yaha pe nahi karna tha
            }
        }
    }
    
    vector<pair<pair<int,int>,int> > result;
        
    for(int i =2 ; i<= n ;i++){
            result.push_back({{parent[i],i},key[i]});
    }
    
    return result;
}
