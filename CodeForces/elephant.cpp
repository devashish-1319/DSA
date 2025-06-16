#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x<=5){
        cout<<"1"<<endl;
        return 0;
    }
    int answer=0;
    if(x%5==0){
        answer=x/5;
    }
    else{
        answer=x/5 + 1;
    }
    cout<<answer<<endl;
}