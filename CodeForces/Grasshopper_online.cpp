#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,k;
        cin>>x>>k;
        if(x%k!=0){
            cout<<1<<endl;
            cout<<x<<endl;
        }
        else{
            for(int a=1;a<x;a++){
                if(a%k!=0 && (x-1)%k!=0){
                    cout<<2<<endl;
                    cout<<a<<" "<<x-a<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}