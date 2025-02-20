#include<iostream>
using namespace std;

int findunique(int *arr,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[5]={2,4,6,2,4};
    int n=5;
    
    cout<<findunique(arr,n)<<endl;
    return 0;
    
}