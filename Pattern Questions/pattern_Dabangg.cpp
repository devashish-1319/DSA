#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int count=n-i+1;
        int j=1;
        while(count){
            cout<<j;
            count=count-1;
            j=j+1;
        }
        int k=2;
        while(k<=i){
            cout<<"*";
            k=k+1;
        }
        int o=2;
        while(o<=i){
            cout<<"*";
            o=o+1;
        }
        int staro=n-i+1;
        while(staro){
            cout<<staro;
            staro=staro-1;
        }
        cout<<endl;
        i=i+1;
    }
}
