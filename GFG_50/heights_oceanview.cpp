#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&arr,vector<int>&ans){
    int n=arr.size();
    ans.push_back(n-1);
    int maxi=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(i);
            maxi=arr[i];
        }
    }
    sort(ans.begin(),ans.end());
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
    solve(arr,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
