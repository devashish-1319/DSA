#include<iostream>

using namespace std;

bool isDivisible(int n){
    if(n%3==0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool vanyawins=false;
        for(int move=1;move<=10;move++){
            if(move%2==1){ //vanya ki baari
                if(isDivisible(n+1)){
                    vanyawins=true;
                    break;
                }
                else if(isDivisible(n-1)){
                    vanyawins=true;
                    break;
                }
            }
            if(n%3==1){
                n--;
            }
            else if(n%3==2){
                n++;
            }
        }
        if(vanyawins){
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }

    }
}