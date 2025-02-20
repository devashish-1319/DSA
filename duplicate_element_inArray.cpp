#include<iostream>
using namespace std;

int findsuplicate(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<n;i++){
        ans=ans^i;
    }
    return ans;
}
int main(){
    int arr[6]={1,3,4,2,2,5};
    int n=6;
    
    cout<<findsuplicate(arr,n)<<endl;
    return 0;
}