#include<vector>
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
        if(n%2==0){ //even 
            return 1 + recursion(n/2);
        }
        else{ //odd
            return 1 + recursion(n-1);
        }
    }
    int topdown(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n%2==0){
            return 1+ topdown(n/2,dp);
        }
        else{
            return 1 + topdown(n-1,dp);
        }
    }
    int bottomup(int n){
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                dp[i]= 1+ dp[i/2];
            }
            else{
                dp[i]= 1+dp[i-1];
            }
        }
        return dp[n];
    }
    int spaceopti(int n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;   // reverse of doubling
            } else {
                n -= 1;   // reverse of +1
            }
            count++;
        }
        return count;
    }

    int minOperation(int n) {
        // code here.
        //return recursion(n);
        //vector<int>dp(n+1,-1);
        //return topdown(n,dp);
        //return bottomup(n);
        return spaceopti(n);
    }
};