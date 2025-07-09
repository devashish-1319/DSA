#include<iostream>
using namespace std;

int binarysearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    
    int mid=(start+end)/2;
    
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        if(key<arr[mid]){
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}

int main(){
    int even[6]={-1,3,6,7,8,98};
    int odd[5]={0,7,45,67,88};
    
    int index=binarysearch(even,6,6);
    cout<<"index of 6 is:"<<index<<endl;
}