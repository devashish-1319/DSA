//USING DFS ALGO

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void toposort(int V,vector<bool> &visited,stack<int> &s,vector<int> adj[]){
	    visited[V]=1;
	    for(auto nbr:adj[V]){
	        if(!visited[nbr]){
	            toposort(nbr,visited,s,adj);
	        }
	    }
	    s.push(V);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>visited(V,0);
	    stack<int>s;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            toposort(i,visited,s,adj);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

//USING KAHN ALGO - (BFS)

class Solution2
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
	    vector<int>ans;
	    while(!q.empty()){
	        int front=q.front();
	        q.pop();
	        ans.push_back(front);
	        for(auto nbr:adj[front]){
	            indegree[nbr]--;
	            if(indegree[nbr]==0){
	                q.push(nbr);
	            }
	        }
	    }
	    return ans;
	}
};

