#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remainingpart=isSorted(arr+1,size-1);
        return remainingpart;
    }
}
int main(){
    int arr[5]={2,3,4,5,6};
    int size=5;
    
    bool ans=isSorted(arr,size);
    
    if(ans){
        cout<<"Array is sortred"<<endl;
    }
    else{
        cout<<"Array ius not sorted"<<endl;
    }
    return 0;
}