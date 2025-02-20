#include<iostream>
using namespace std;

int function(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    int ans=function(n-1)+function(n-2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cout<<function(i)<<" ";
    }  
}