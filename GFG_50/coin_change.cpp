#include<vector>
using namespace std;
class Solution {
  public:
    int recursion(vector<int> &coins,int sum){
        if(sum==0){
            return 0;
        }
        if(sum<0){
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=recursion(coins,sum-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans); //+1 COIN
            }
        }
        return mini;
    }
    int topdown(vector<int>&coins,int sum,vector<int>&dp){
        if(sum==0){
            return 0;
        }
        if(sum<0){
            return -1;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=topdown(coins,sum-coins[i],dp);
            if(ans!=-1){
                mini=min(mini,1+ans);
            }
        }
        if(mini==INT_MAX){
            return -1;
        }
        else{
            return dp[sum]=mini;
        }
    }
    int bottomup(vector<int>&coins,int sum){
        vector<int>dp(sum+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=sum;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[sum]==INT_MAX){
            return -1;
        }
        return dp[sum];
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
       // return recursion(coins,sum);
       //vector<int>dp(sum+1,-1);
       //return topdown(coins,sum,dp);
       return bottomup(coins,sum);
    }
};