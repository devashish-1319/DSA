#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter your number"<<endl;
    cin>>n;

    int ans=0;
    while(n!=0){
        int digit=n%10;
         ans=ans*10+digit;
        n=n/10;
    }
    cout<<ans<<endl;
}