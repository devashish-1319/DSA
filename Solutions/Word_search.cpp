#include<iostream>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>> &board,string &word,int i,int j,int id){
        if(id==word.size()){
            return true; //word found this means
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[id]){
            return false;
        }
        char temp=board[i][j]; //save current character 
        board[i][j]='#'; //mark visited
        
        bool found= dfs(board,word,i+1,j,id+1)||dfs(board,word,i-1,j,id+1)||dfs(board,word,i,j+1,id+1)||dfs(board,word,i,j-1,id+1);

        board[i][j]=temp; //this is called back track, we assigned the previously stored value once again.
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};