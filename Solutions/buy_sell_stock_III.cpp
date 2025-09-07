#include<iostream>
using namespace std;
//3D DP QUESTION 
int recursion(vector<int> &prices,int buy,int index,int limit){
        int n=prices.size();
        if(index==n){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyit= -prices[index] + recursion(prices,0,index+1,limit);
            int dontbuy= 0 + recursion(prices,1,index+1,limit);
            profit=max(buyit,dontbuy);
        }
        else{
            int sellit=prices[index] + recursion(prices,1,index+1,limit-1);
            int dontsell=0 + recursion(prices,0,index+1,limit);
            profit=max(sellit,dontsell);
        }
        return profit;
    }
    int topdown(vector<int> &prices,int buy,int index,int limit,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        if(index==n){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[buy][index][limit]!=-1){
            return dp[buy][index][limit];
        }
        int profit=0;
        if(buy){
            int buyit= -prices[index] + topdown(prices,0,index+1,limit,dp);
            int dontbuy= 0 + topdown(prices,1,index+1,limit,dp);
            profit=max(buyit,dontbuy);
        }
        else{
            int sellit=prices[index] + topdown(prices,1,index+1,limit-1,dp);
            int dontsell=0 + topdown(prices,0,index+1,limit,dp);
            profit=max(sellit,dontsell);
        }
        return dp[buy][index][limit]=profit;
    }
    int bottomup(vector<int>&prices){
        int n=prices.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<3;limit++){
                    int profit=0;
                    if(buy){
                        int buyit=-prices[i] + dp[0][i+1][limit];
                        int dontbuy=0+ dp[1][i+1][limit];
                        profit=max(buyit,dontbuy);
                    }
                    else{
                        int sellit=prices[i] + dp[1][i+1][limit-1];
                        int dontsell= 0 + dp[0][i+1][limit];
                        profit=max(sellit,dontsell);
                    }
                    dp[buy][i][limit]=profit;
                }
            }
        }
        return dp[1][0][2];
    }
    int spaceopti(vector<int> &prices){
        int n=prices.size();
        vector<vector<int>>next(2,vector<int>(3.0)),curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int limit=1;limit<3;limit++){
                    int profit=0;
                    if(buy){
                        int buyit=-prices[i] + next[0][limit];
                        int dontbuy=0+ next[1][limit];
                        profit=max(buyit,dontbuy);
                    }
                    else{
                        int sellit=prices[i] + next[1][limit-1];
                        int dontsell=0+ next[0][limit];
                        profit=max(sellit,dontsell);
                    }
                    curr[buy][limit]=profit;
                }
            }
            next=curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        //return recursion(prices,1,0,2);
        //vector<vector<vector<int>>>dp(2,vector<vector<int>>(prices.size()+1,vector<int>(3,-1)));
        //return topdown(prices,1,0,2,dp);
        //return bottomup(prices);
        return spaceopti(prices);
    }
