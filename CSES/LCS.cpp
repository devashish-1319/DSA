#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int>ans;
int recursion(vector<int> &nums1,vector<int>&nums2,int i,int j){
    if(i==nums1.size() || j==nums2.size()){
        return 0;
    }
    if(nums1[i]==nums2[j]){
        ans.push_back(nums1[i]);
        return 1 + recursion(nums1,nums2,i+1,j+1);
    }
    else{
        return max(recursion(nums1,nums2,i+1,j),recursion(nums1,nums2,i,j+1));
    }
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<int>nums1(n);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    
    vector<int>nums2(m);
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    
    int lcs=recursion(nums1, nums2, 0, 0);
    cout<<lcs<<endl;
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}