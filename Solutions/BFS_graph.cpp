//{ Driver Code Starts
//#include <bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>
// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> adj[],vector<bool> &visited,
             vector<int> &ans,int V){
        queue<int>q;
        q.push(V);
        visited[V]=1;
        while(!q.empty()){
            int frontnode=q.front();
            q.pop();
            ans.push_back(frontnode);
            for(auto i:adj[frontnode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visited(V,false);
        //for(int i=0;i<V;i++){
            //if(!visited[i]){
        bfs(adj,visited,ans,0);
            //}
       // }
        return ans;
        
    }
};

//{ Driver Code Starts.
/*int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends*/