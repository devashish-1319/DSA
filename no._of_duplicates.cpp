#include<iostream>
#include<unordered_map>
using namespace std;

int solve(int arr[],int n){
    unordered_map<int,int>duplicates;
    for(int i=0;i<n;i++){
        duplicates[arr[i]]++;
    }
    int duplicatecount=0;
    for(auto i : duplicates){
        if(i.second>1){
            duplicatecount++;
        }
    }
    return duplicatecount;
}
int main(){
    int arr[8]={1,3,5,3,6,7,8,8};
    int n=8;
    int ans=solve(arr,n);
    cout<<"No. of duplicates :"<<ans<<endl;
    return 0;
}