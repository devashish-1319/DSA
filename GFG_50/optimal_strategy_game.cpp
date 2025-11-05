#include<vector>
using namespace std;
class Solution {
  public:
    int recursion(vector<int> &arr,int i,int j){
        if(i==j){
            return arr[i];
        }
        if(i+1==j){
            return max(arr[i],arr[j]);
        }
        int pickleft=arr[i]+ min(recursion(arr,i+2,j),recursion(arr,i+1,j-1));
        int pickright=arr[j]+ min(recursion(arr,i,j-2),recursion(arr,i+1,j-1));
        return max(pickleft,pickright);
    }
    int topdown(vector<int> &arr,int i,int j,vector<vector<int>>&dp){
        if(i==j){
            return arr[i];
        }
        if(i+1==j){
            return max(arr[i],arr[j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int pickleft=arr[i]+ min(topdown(arr,i+2,j,dp),topdown(arr,i+1,j-1,dp));
        int pickright=arr[j]+ min(topdown(arr,i,j-2,dp),topdown(arr,i+1,j-1,dp));
        return dp[i][j]=max(pickleft,pickright);
    }
    int bottomup(vector<int>&arr){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=arr[i];
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=max(arr[i],arr[i+1]);
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                int pickleft=arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
                int pickright=arr[j] + min(dp[i][j-2],dp[i+1][j-1]);
                
                //boundary cases
                if(i+2>j){
                    pickleft=arr[i] + dp[i+1][j-1];
                }
                if(i>j-2){
                    pickright=arr[j]+ dp[i+1][j-1];
                }
                dp[i][j]=max(pickleft,pickright);
            }
        }
        return dp[0][n-1];
    }
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        //return recursion(arr,0,n-1);
        //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //return topdown(arr,0,n-1,dp);
        return bottomup(arr);
        
    }
};