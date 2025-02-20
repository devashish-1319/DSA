// USING DFS ALGO

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool checkcycleDFS(int V,vector<bool> &visited,vector<bool> &dfsvisited,
    vector<int> adj[]){
        visited[V]=true;
        dfsvisited[V]=true;
        for(auto nbr:adj[V]){
            if(!visited[nbr]){
                bool cycleDetected=checkcycleDFS(nbr,visited,dfsvisited,adj);
                if(cycleDetected){
                    return true;
                }
            }
            else if(dfsvisited[nbr]){
                return true;
            }
        }
        dfsvisited[V]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>dfsvisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool cyclefound=checkcycleDFS(i,visited,dfsvisited,adj);
                if(cyclefound){
                    return true;
                }
            }
        }
        return false;
    }
};

//USING BFS ALGO

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j: adj[i]){
	            indegree[j]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int count=0;
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        count++;
	        for(auto nbr:adj[front]){
	            indegree[nbr]--;
	            if(indegree[nbr]==0){
	                q.push(nbr);
	            }
	        }
	    }
	    if(count==V){
	        return false;
	    }
	    else{
	        return true;
	    }
    }
};