#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter the value of a and b"<<endl;
    cin>>a;
    cin>>b;
    char op;
    cout<<"enter operator"<<endl;
    cin>>op;
    switch(op){
        case '+': cout<<a+b<<endl;
                  break;
        case '-': cout<<a-b<<endl;
                  break;
        case '*': cout<<a*b<<endl;
                  break;
        case '/': cout<<a/b<<endl;
                  break;
        default : cout<<"enter a valid operator"<<endl;
                  break;
    }
}
   
    
    