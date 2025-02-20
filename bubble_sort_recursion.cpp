#include<iostream>
using namespace std;

void bubblesort(int *arr,int n){
    int t;
    //base case
    if(n==0 || n==1){
        return ;
    }
    
    //1 case ko solve
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
        }
    }
    bubblesort(arr,n-1);
}
int main(){
    int arr[5]={5,2,7,8,4};
    
    bubblesort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}