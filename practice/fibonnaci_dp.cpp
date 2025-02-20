//recursive solution 

#include<iostream>
using namespace std;

// int recursive(int n){
//     if(n==0){
//         return n;
//     }
//     if(n==1){
//         return n;
//     }
//     int ans=recursive(n-1)+recursive(n-2);
//     return ans;
// }

// int memorization(int n,vector<int> &dp){
//     if(n==0 || n==1){
//         return n;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     dp[n]=memorization(n-1,dp)+ memorization(n-2, dp);
//     int ans=dp[n];
//     return ans;
// }



int main(){
    int n;
    cin>>n;
    //cout<<recursive(n)<<endl;
    vector<int>dp(n+1,-1);
   
    //cout<<memorization(n, dp)<<endl;
}