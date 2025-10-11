#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int recursion(string &text1,string &text2,int i,int j){
        if(i==text1.size()){
            return 0;
        }
        if(j==text2.size()){
            return 0;
        }
        if(text1[i]==text2[j]){
            return 1+recursion(text1,text2,i+1,j+1);
        }
        else{
            return max(recursion(text1,text2,i+1,j),recursion(text1,text2,i,j+1));
        }
    }
    int topdown(string &text1,string &text2,int i,int j,vector<vector<int>> &dp){
        if(i==text1.size()){
            return 0;
        }
        if(j==text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            dp[i][j]=1+topdown(text1,text2,i+1,j+1,dp);
        }
        else{
            dp[i][j]=max(topdown(text1,text2,i+1,j,dp),topdown(text1,text2,i,j+1,dp));
        }
        return dp[i][j];
    }
    int bottomup(string &text1,string &text2){
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int space(string &text1,string &text2){
        int n=text1.size();
        int m=text2.size();
        vector<int>curr(m+1,0),next(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    curr[j]=1+next[j+1];
                }
                else{
                    curr[j]=max(next[j],curr[j+1]);
                }
            }
            next=curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        //return recursion(text1,text2,0,0);
        //vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        //return topdown(text1,text2,0,0,dp);
        //return bottomup(text1,text2);
        return space(text1,text2);
    }
};