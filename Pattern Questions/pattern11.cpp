#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<i){
            cout<<" ";
            j=j+1;
        }
        int star=n-i+1;
        int value=i;
        while(star){
            cout<<value;
            value=value+1;
            star=star-1;
        }
        cout<<endl;
        i=i+1;
    }
}