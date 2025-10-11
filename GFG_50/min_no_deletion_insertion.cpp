#include<vector>
#include<string>
using namespace std;
class Solution {

  public:
    int recursionlcs(string &s1,string &s2,int i,int j){
        if(i==0 || j==0){
            return 0;
        }
        if(s1[i-1]==s2[j-1]){
            return 1 + recursionlcs(s1,s2,i-1,j-1);
        }
        else{
            return max(recursionlcs(s1,s2,i-1,j),recursionlcs(s1,s2,i,j-1));
        }
    }
    int topdown(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==0 || j==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=1+topdown(s1,s2,i-1,j-1,dp);
        }
        else{
            return dp[i][j]=max(topdown(s1,s2,i-1,j,dp),topdown(s1,s2,i,j-1,dp));
        }
    }
    int bottomup(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int spaceopti(string &s1,string &s2){
        int n=s1.size();
        int m=s2.size();
        vector<int>curr(m+1,0),prev(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        //longest common subsequence approach
        //int lcs=recursionlcs(s1,s2,s1.size(),s2.size());
        
        //vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        //int lcs=topdown(s1,s2,s1.size(),s2.size(),dp);
        //int lcs=bottomup(s1,s2);
        int lcs=spaceopti(s1,s2);
        return (s1.size()-lcs)+(s2.size()-lcs); //formula through intution
    }
};