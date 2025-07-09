#include<iostream>
#include <ostream>
using namespace std;
int main(){
    int n;
    cout<<"enter your number:"<<endl;
    cin>>n;
    int i=0;
    int ans=0;
    while(n!=0){
        int digit=n%10;
        if(digit==1){
            ans=ans+pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<"answer is : "<<ans<<endl;
    return 0;
}