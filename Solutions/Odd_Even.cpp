#include<iostream>
using namespace std;

bool isEven(int a){
    if(a%2==0){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int a;
    cin>>a;
    
    if(isEven(a)){
        cout<<"number is even"<<endl;
    }
    else{
        cout<<"number is odd"<<endl;
    }
}
    