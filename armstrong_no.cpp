#include<iostream>
#include<math.h>
using namespace std;

bool isArmstrong(int num){
    int k=to_string(num).length();
    int sum=0;
    int n=num;
    while(n>0){
        int digit=n%10;
        sum=sum + pow(digit,k);
        n=n/10;
    }
    if(sum==num){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cout<<"enter your number"<<endl;
    cin>>n;

    if(isArmstrong(n)){
        cout<<"It is an Armstrong number"<<endl;
    }
    else{
        cout<<"It is not an Armstrong number"<<endl;
    }
    return 0;
}