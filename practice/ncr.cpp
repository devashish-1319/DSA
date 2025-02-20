#include<iostream>
using namespace std;

int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int ncr(int n,int r){
    int numerator=factorial(n);
    int denominator=factorial(r)*factorial(n-r);
    int answer=numerator/denominator;
    return answer;
}
int main(){
    int n,r;
    cout<<"enter the value of n and r"<<endl;
    cin>>n>>r;

    cout<<"factorial is "<<factorial(n)<<endl;
    cout<<"ncr is "<<ncr(n,r);
}