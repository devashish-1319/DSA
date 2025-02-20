#include<iostream>
using namespace std;

void bubblesort(int arr[],int n){
    int t;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}

int main(){
    int arr[5]={3,6,4,8,0};
    cout<<"question array:"<<" ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubblesort(arr,5);
    cout<<"the sorted array is:"<<" ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}