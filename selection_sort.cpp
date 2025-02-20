#include<iostream>
using namespace std;
//recursive solution
void sortRecursion(int arr[],int n){
    int i=0;
    if(i==n-1){
        return ;
    }
    int mini=i;
    for(int j=i;j<n;j++){
        if(arr[j]<arr[mini]){
            mini=j;
        }
    }
    swap(arr[mini],arr[i]);
    i++;
    sortRecursion(arr, n);
}
//iterative solution
void selectionsort(int arr[],int n){
    int t;
    for(int i=0;i<n-1;i++){
        int minindex=i;
        
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        //swap(arr[minindex],arr[i]);
        t=arr[minindex];
        arr[minindex]=arr[i];
        arr[i]=t;
    }
}

int main(){
    int arr[5]={3,6,4,8,0};
    cout<<"question array:"<<" ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionsort(arr,5);
    cout<<"the sorted array is:"<<" ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}