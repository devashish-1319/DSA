#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int count=0;
    while(n>0){
        long long digit=n%10;
        if(digit==4 || digit==7){
            count++;
        }
        n=n/10;
    }
    if(count==4 || count==7){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}