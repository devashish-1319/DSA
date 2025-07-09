#include<iostream>
using namespace std;

void insert(int arr[], int i)
{
    //code here
    int t;
    if(i==0){
        return ;
    }
    if(arr[i]<arr[i-1]){
        t=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=t;
    }
    else{
        return ;
    }
    insert(arr,i-1);
}
    
//Function to sort the array using insertion sort algorithm.
void insertionSort(int arr[], int n)
{
    //code here
    if(n==0){
        return ;
    }
    insertionSort(arr,n-1);
    insert(arr,n-1);
}