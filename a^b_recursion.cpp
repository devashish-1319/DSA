#include<iostream>
using namespace std;

double power(double a,long b){
    
    //base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    if(b<0){
        b=b*(-1);
        a=1/a;
    }
    
    double ans=power(a,b/2);
    
    //if b is even 
    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    double ans=power(a,b);
    
    cout<<"answer is"<<ans<<endl;
    
    return 0;
}