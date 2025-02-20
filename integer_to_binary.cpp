#include<iostream>
#include<string>
using namespace std;
//will convert any number to its binary form//
int main(){
    int n;
    cout<<"enter an integer: "<<endl;
    cin>>n;

    string binary="";
    if(n==0){
        binary="0";
    }
    else{
        while(n>0){
            binary=char((n%2)+'0')+binary;
            n=n/2;
        }
    }
    cout<<"Binary representaion is :"<<binary<<endl;
    return 0;
}