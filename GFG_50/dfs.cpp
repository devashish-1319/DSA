#include<vector>
using namespace std;
class Solution {
  public:
    void solve(int node,vector<vector<int>>& adj,vector<bool>&visited,vector<int>&ans){
        visited[node]=1;
        ans.push_back(node);
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                solve(neighbour,adj,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>visited(n,0);
        vector<int>ans;
        solve(0,adj,visited,ans);
        return ans;
    }
};