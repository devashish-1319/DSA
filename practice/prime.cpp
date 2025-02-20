#include<iostream>
#include <ostream>
using namespace std;

int main(){
    int n;
    cout<<"enter your number"<<endl;
    cin>>n;
    bool isprime=1;
    int i=2;
    while(i<n){
        if(n%i==0){
            //cout<<"not a prime"<<endl;
            isprime=0;
        }
        i=i+1;
    }
    if(isprime==1){
        cout<<"it is a prime no."<<endl;
    }
    else{
        cout<<"it is not a prime no."<<endl;
    }
}