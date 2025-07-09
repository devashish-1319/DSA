
#include <iostream>
#include<vector>
using namespace std;
#define MOD 1000000007


class Solution {
  private:
    long long int solve(int n,vector<long long int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=(solve(n-1,dp)+solve(n-2,dp))%MOD;
        return dp[n];
    }
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1,-1);
        //for(int i=0;i<=n;i++){
          //  dp[i]=-1;
        //}
        return solve(n,dp);
    }

    /****************************************************/
    long long int bottomUp(int n) {
        // code here
        vector<long long int>dp2(n+1);
        dp2[0]=0;
        dp2[1]=1;
        for(int i=2;i<=n;i++){
            dp2[i]=(dp2[i-1]+dp2[i-2])%MOD;
        }
        return dp2[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends