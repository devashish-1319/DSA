//USING DFS ALGO
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleDFS(int V,int parent,vector<bool> &visited,vector<int> adj[]){
        visited[V]=true;
        for(auto nbr:adj[V]){
            if(!visited[nbr]){
                bool cycledetected=isCycleDFS(nbr,V,visited,adj);
                if(cycledetected){
                    return 1;
                }
            }
            else if(nbr!=parent){
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCycleDFS(i, -1, visited, adj)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//USING BFS ALGO

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycleBFS(int V,vector<bool> &visited,vector<int> adj[],vector<int> &parent){
        
        visited[V]=true;
        queue<int>q;
        q.push(V);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto nbr:adj[front]){
                if(visited[nbr]==true && nbr!=parent[front]){
                    return true;
                }
                else if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=front;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        vector<int>parent(V,-1);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=iscycleBFS(i,visited,adj,parent);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};

