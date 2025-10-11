#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<bool>visited(n,0);
        queue<int>q;
        visited[0]=1;
        q.push(0);
        while(!q.empty()){
            int front=q.front(); q.pop();
            ans.push_back(front);
            
            for(int neighbour : adj[front]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};