#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
     bool dfs(int start,int parent,vector<vector<int>>&adj,vector<bool> &visited){
        visited[start]=true;
        for(int neighbour : adj[start]){
            if(!visited[neighbour]){
                if(dfs(neighbour,start,adj,visited)){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
    bool bfs(int start,vector<vector<int>>&adj,vector<bool>&visited){
        queue<pair<int,int>>q;
        visited[start]=1;
        q.push({start,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(int neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push({neighbour,node});
                }
                else if(neighbour != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                   return true;
                }
            }
        }
        return false;
        
    }
};