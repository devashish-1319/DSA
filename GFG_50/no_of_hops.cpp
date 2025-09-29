#include<vector>
using namespace std;
class Solution {
  public:
   //this is not a staircase problem, therefore just add everything 
    // Function to count the number of ways in which frog can reach the top.
    int recursion(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        int step1=recursion(n-1);
        int step2=recursion(n-2);
        int step3=recursion(n-3);
        return step1+step2+step3;
    }
    int topdown(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int step1=topdown(n-1,dp);
        int step2=topdown(n-2,dp);
        int step3=topdown(n-3,dp);
        return dp[n]=step1+step2+step3;
    }
    int bottomup(int n){
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
    int spaceopti(int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int prev3=1;
        int prev2=1;
        int prev1=2;
        for(int i=3;i<=n;i++){
            int curr=prev1+prev2+prev3;
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int countWays(int n) {

        // your code here
        //return recursion(n);
        //vector<int>dp(n+1,-1);
        //return topdown(n,dp);
        //return bottomup(n);
        return spaceopti(n);
    }
};
