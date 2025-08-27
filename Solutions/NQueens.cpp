//both nqueens 1 and 2 here
#include<iostream>
using namespace std;
bool issafe(vector<string> & board,int row,int col,int n){
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagnal
        for(int i=row,j=col ; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col ;i>=0 && j<n ; i--, j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>board,int row,int n,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        solve(board,0,n,ans);
        return ans; 
    }


/****************************************************** */

bool isssafe(vector<string> & board,int row,int col,int n){
        //horizontal
        /*for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }*/
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagnal
        for(int i=row,j=col ; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col ;i>=0 && j<n ; i--, j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>board,int row,int n,int &count){
        if(row==n){
            count++;
            return ;
        }
        for(int j=0;j<n;j++){
            if(isssafe(board,row,j,n)){
                board[row][j]='Q';
                solve(board,row+1,n,count);
                board[row][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<string>board(n,string(n,'.'));
        solve(board,0,n,count);
        return count;
    }