#include<iostream>
using namespace std;

int function(int n){
    if(n==0){
        return 1;
    }
    int smallproblem=function(n-1);
    int bigproblem=2*smallproblem;
    return bigproblem;
}
int main(){
    cout<<"enter your number"<<endl;
    int n;
    cin>>n;
    cout<<function(n)<<endl;
}