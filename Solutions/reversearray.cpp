#include<iostream>
using namespace std;

void reverse(int arr[],int n){
    
    int start=0;
    int end=n-1;
    
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[6]={1,4,0,5,-3,5};
    int brr[6]={2,6,3,9,4};
    
    reverse(arr,6);
    reverse(brr,5);
    
    printarray(arr, 6);
    printarray(brr, 5);
    
    return 0;
}