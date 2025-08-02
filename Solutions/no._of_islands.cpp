using namespace std;
#include<vector>
#include<queue>

class Solution {
  public: 
    void bfs(int row,int col,vector<vector<bool>> &visited,vector<vector<char>>& grid){
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int newrow=row+delrow;
                    int newcol=col+delcol;
                    
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]=='L' && !visited[newrow][newcol]){
                        visited[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
    }
    void dfs(int row,int col,vector<vector<bool>> &visited,vector<vector<char>>& grid){
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int newrow=row+delrow;
                int newcol=col+delcol;
                
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]=='L' && !visited[newrow][newcol]){
                    dfs(newrow,newcol,visited,grid);
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !visited[i][j]){
                    count++;
                    bfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};