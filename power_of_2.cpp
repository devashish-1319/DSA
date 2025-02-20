#include<iostream>
using namespace std;

int power(int n){
    if(n==0){
        return 1;
    }
    int smallProb=power(n-1);
    int bigProb=2*smallProb;

    return bigProb;
}
int main(){
    int n;
    cout<<"enter the value of n:"<<endl;
    cin>>n;

    cout<<"answer is:"<<power(n)<<endl;
    return 0;

}