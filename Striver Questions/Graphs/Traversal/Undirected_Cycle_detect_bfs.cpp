#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool bfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> adj){
        
        visited[src] = 1;
        
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode: adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(parent != adjNode){
                    return true;
                }
            }
        }
        return false;
    }
    
    // bool dfs(unordered_map<int, bool> &visited, unordered_map<int, list<int>>& adj, int node, int parent){
        
    //     visited[node] = true;
        
    //     for(auto neighbour: adj[node]){
    //         if(!visited[neighbour]){
    //             bool ans = dfs(visited, adj, neighbour, node);
                
    //             if(ans) return true;
    //         }
            
    //         else if(neighbour != parent){
    //             return true;
    //         }
    //     }
        
    //     return false;
    // }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, bool> visited;
        vector<vector<int>> adj;
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
                
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfs(i, visited, adj))
                    return true;
            }
        }
        return false;
    }
};