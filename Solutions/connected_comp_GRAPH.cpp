#include<vector>
using namespace std;
class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &components){
        visited[node]=true;
        components.push_back(node);
        
        for(auto &neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour,adj,visited,components);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,false);
        vector<vector<int>>result;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>components;
                dfs(i,adj,visited,components);
                result.push_back(components);
            }
        }
        return result;
    }
};