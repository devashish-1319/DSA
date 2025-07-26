#include<vector>
using namespace std;
class Solution {
  public:
    //2D DP
    int recursion(vector<int> &weight,vector<int> &value,int index,int W){
        if(index==0){
            if(weight[0]<=W){
                return value[0];
            }
            else{
                return 0;
            }
        }
        int include=0;
        if(weight[index]<=W){
            include=value[index]+recursion(weight,value,index-1,W-weight[index]);
        }
        int exclude=0+recursion(weight,value,index-1,W);
        int ans=max(include,exclude);
        return ans;
    }
    int memorization(vector<int> &weight,vector<int> &value,int index,int W,vector<vector<int>> &dp){
        if(index==0){
            if(weight[0]<=W){
                return value[0];
            }
            else{
                return 0;
            }
        }
        if(dp[index][W]!=-1){
            return dp[index][W];
        }
        int include=0;
        if(weight[index]<=W){
            include=value[index]+memorization(weight,value,index-1,W-weight[index],dp);
        }
        int exclude=0+memorization(weight,value,index-1,W,dp);
        
        dp[index][W]=max(include,exclude);
        return dp[index][W];
    }
    int tabulation(vector<int> &weight,vector<int> &value,int index,int W){
        int n=weight.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int w=weight[0];w<=W;w++){
            if(weight[0]<=w){
                dp[0][w]=value[0];
            }
            else{
                dp[0][w]=0;
            }
        }
        for(int index=1;index<n;index++){
            for(int w=0;w<=W;w++){
                int include=0;
                if(weight[index]<=w){
                    include=value[index]+dp[index-1][w-weight[index]];
                }
                int exclude=0+dp[index-1][w];
                dp[index][w]=max(include,exclude);
            }
        }
        return dp[n-1][W];
    }
    int spaceotpi(vector<int> &weight,vector<int> &value,int n,int capacity){
       
       //doubt
       return 0;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int index=wt.size()-1;
        //return recursion(wt,val,index,W);
        //vector<vector<int>>dp(wt.size(),vector<int>(W+1,-1));
        //return memorization(wt,val,index,W,dp);
        return tabulation(wt,val,index+1,W);
        
    }
};