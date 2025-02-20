#include<iostream>
using namespace std;
/*
//recursive factorial//
int refact(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*refact(n-1);
}
*/
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int ncr(int n,int r){
    int nom=factorial(n);
    int denom=factorial(r)*factorial(n-r);
    return nom/denom;
}
int main(){
    int n,r;
    cin>>n>>r;
    cout<<"factorial is:"<<factorial(n)<<endl;
    cout<<"ncr is:"<<ncr(n,r)<<endl;
}
