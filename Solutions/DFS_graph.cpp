//{ Driver Code Starts
#include <iostream>
using namespace std;
#include<vector>

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int V,vector<bool> &visited,vector<int>adj[],vector<int> &component){
        component.push_back(V);
        visited[V]=true;
        for(auto i:adj[V]){
            if(!visited[i]){
                dfs(i,visited,adj,component);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        vector<int>component;
        dfs(0,visited,adj,component);
        
        return component;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends