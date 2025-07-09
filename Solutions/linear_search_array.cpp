#include<iostream>
using namespace std;
bool search(int a[],int n,int key){
    for(int i=0;i<n;i++){
        if(a[i]==key){
            return 1;
        }
    }
    return 0;
    }

int main(){
    int a[10]={5,9,-2,3,0,76,45,33,12,15};
    cout<<"enter number to search"<<endl;
    int key;
    cin>>key;
    bool found=search(a,10,key);
    if(found){
        cout<<"number found"<<endl;
    }
    else{
        cout<<"number not found"<<endl;
    }
}