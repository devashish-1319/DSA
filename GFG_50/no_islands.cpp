#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<bool>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        
        int drow[]={1,-1,0,0,1,-1,1,-1};
        int dcol[]={0,0,1,-1,1,1,-1,-1};
        visited[row][col]=true;
        q.push({row,col});
        
        while(!q.empty()){
            pair<int,int>front=q.front(); q.pop();
            int r=front.first;
            int c=front.second;
            for(int i=0;i<8;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='L'){
                    visited[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        if(n==0){
            return 0;
        }
        int m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !visited[i][j]){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};