#include<iostream>
using namespace std;

int main(){
    int arr[6]={1,2,3,4,5,6};
    int n=6;
    int start=0;
    int end=n-1;
    int t;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}