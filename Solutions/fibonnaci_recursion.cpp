#include<iostream>
using namespace std;

class Solution {
public:
    int recursion(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int ans;
        return ans=recursion(n-1)+recursion(n-2);
    }
    int memorization(int n,vector<int> &dp){ //top down approach
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=memorization(n-1,dp)+memorization(n-2,dp);
        return dp[n];
    }
    int tabulation(int n){

        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int spaceoptimisation(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int prev=0;
        int next=1;

        for(int i=2;i<=n;i++){
            int curr=prev+next;
            prev=next;
            next=curr;
        }
        return next;
    }
    int fib(int n) {
        //return recursion(n);
        //vector<int>dp(n+1,-1);
        //return memorization(n,dp);
        //return tabulation(n);
        return spaceoptimisation(n);
    }
};
/*int main(){
    int n;
    cin>>n;
    int result;
    result=fib(n);
    
    cout<<"result is-"<<result<<endl;
}*/
