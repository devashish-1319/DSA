#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter your decimal number:"<<endl;
    cin>>n;

    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1;
        ans=(bit*pow(10,i))+ans;
        n=n>>1;
        i++;
    }
    cout<<"answer is:"<<ans<<endl;
    return 0;
}