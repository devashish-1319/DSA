#include<iostream>
using namespace std;
class Solution {
public:
    //buy or sell -> dono mai include exclude
    // buy -sell -buy -sell ......
    int recursion(vector<int> &prices,int buy,int index){
        int n=prices.size();
        if(index==n){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyit= -prices[index] + recursion(prices,0,index+1);
            int dontbuy= 0 + recursion(prices,1,index+1);
            profit=max(buyit,dontbuy);
        }
        else{
            int sellit=prices[index] + recursion(prices,1,index+1);
            int dontsell=0 + recursion(prices,0,index+1);
            profit=max(sellit,dontsell);
        }
        return profit;
    }
    int topdown(vector<int> &prices,int buy,int index,vector<vector<int>>&dp){
        int n=prices.size();
        if(index==n){
            return 0;
        }
        if(dp[buy][index]!=-1){
            return dp[buy][index];
        }
        int profit=0;
        if(buy){
            int buyit= -prices[index] + topdown(prices,0,index+1,dp);
            int dontbuy= 0 + topdown(prices,1,index+1,dp);
            profit=max(buyit,dontbuy);
        }
        else{
            int sellit=prices[index] + topdown(prices,1,index+1,dp);
            int dontsell=0 + topdown(prices,0,index+1,dp);
            profit=max(sellit,dontsell);
        }
        return dp[buy][index]=profit;
    }
    int bottomup(vector<int> &prices){
        int n=prices.size();
        vector<vector<int>>dp(2,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                int profit;
                if(buy){
                    int buyit= -prices[i] + dp[0][i+1];
                    int dontbuy= 0 + dp[1][i+1];
                    profit=max(buyit,dontbuy);
                }
                else{
                    int sellit=prices[i] + dp[1][i+1];
                    int dontsell=0 + dp[0][i+1];
                    profit=max(sellit,dontsell);
                }
                dp[buy][i]=profit;
            }
        }
        return dp[1][0];
    }
    int spaceopti(vector<int> &prices){
        int n=prices.size();
        //vector<vector<int> >dp(n+1,vector<int>(2,0));
        vector<int>next(2,0);
        vector<int>curr(2,0);
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int buykaro= -prices[index]+ next[0];
                    int skipkaro=0+next[1];
                    profit=max(buykaro,skipkaro);
                }
                else{
                    int sellkaro=prices[index]+ next[1];
                    int skipkaro=0 + next[0];
                    profit=max(sellkaro,skipkaro);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //Greedy approach
        /*int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=(prices[i]-prices[i-1]);
            }
        }
        return profit;*/
        //return recursion(prices,1,0);
        vector<vector<int>>dp(2,vector<int>(n+1,-1));
        //return topdown(prices,1,0,dp);
        return bottomup(prices);
    }
};