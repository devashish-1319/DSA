#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int product=1;
    int sum=0;
    while(n!=0){
        int digit=n%10;
        product=product*digit;
        sum=sum+digit;
        n=n/10;
    }
    int answer=product - sum;
    cout<<answer<<endl;
}