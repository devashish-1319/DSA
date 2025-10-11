#include<vector>
using namespace std;
class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    void solve(int n,vector<int> &ans){
        if(n==ans.size()){
            return ;
        }
        int size=ans.size();
        int next=ans[size-1]+ans[size-2];
        ans.push_back(next);
        solve(n,ans);
    }
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int>ans;
        if(n<=0){
            return ans;
        }
        ans.push_back(0);
        if(n==1){
            return ans;
        }
        ans.push_back(1);
        solve(n,ans);
        return ans;
        
    }
};