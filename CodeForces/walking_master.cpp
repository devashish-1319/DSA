#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        long long r=d-b;
        long long l=r-(c-a);
        if(r<0 || l<0){
            cout<<"-1"<<endl;
        }
        else{
            cout<<r+l<<endl;
        }
    }
    return 0;
}