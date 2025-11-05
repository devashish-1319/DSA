#include<vector>
using namespace std;
class Solution {
  public:
    int recursion(int index,vector<int>&height){
        int n=height.size();
        if(index==n-1){
            return 0;
        }
        int one=recursion(index+1,height) + abs(height[index]-height[index+1]);
        int two=INT_MAX;
        if(index+2<n){
            two=recursion(index+2,height)+ abs(height[index]-height[index+2]);
        }
        return min(one,two);
    }
    int topdown(int index,vector<int>&height,vector<int>&dp){
        int n=height.size();
        if(index==n-1){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int one=topdown(index+1,height,dp)+ abs(height[index]-height[index+1]);
        int two=INT_MAX;
        if(index+2<n){
            two=topdown(index+2,height,dp)+ abs(height[index]-height[index+2]);
        }
        return min(one,two);
    }
    int bottomup(vector<int>&height){
        int n=height.size();
        vector<int>dp(n+1,0);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int one=dp[i+1]+abs(height[i]-height[i+1]);
            int two=INT_MAX;
            if(i+2<n){
                two=dp[i+2]+ abs(height[i]-height[i+2]);
            }
            dp[i]=min(one,two);
        }
        return dp[0];
    }
    int space(vector<int> &height){
        int next1=0; //i+1
        int next2=0; //i+2
        int n=height.size();
        for(int i=n-2;i>=0;i--){
            int one=next1 + abs(height[i]-height[i+1]);
            int two=INT_MAX;
            if(i+2<n){
                two=next2 + abs(height[i]-height[i+2]);
            }
            int curr=min(one,two);
            next2=next1;
            next1=curr;
        }
        return next1;
        
    }
    int minCost(vector<int>& height) {
        // Code here
        //return recursion(0,height);
        //vector<int>dp(height.size()+1,-1);
        //return topdown(0,height,dp);
        //return bottomup(height);
        return space(height);
    }
};