#include<vector>
using namespace std;
class Solution {
  public:
    pair<int,int>solve(vector<int> &arr,int i,int n){
        if(i==n-1){
            return {arr[i],arr[i]};
        }
        pair<int,int>nextpair=solve(arr,i+1,n);
        int currmin=min(arr[i],nextpair.first);
        int currmax=max(arr[i],nextpair.second);
        return {currmin,currmax};
    }
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n<=0){
            return {};
        }
        pair<int,int>result=solve(arr,0,n);
        return {result.first,result.second};
    }
};