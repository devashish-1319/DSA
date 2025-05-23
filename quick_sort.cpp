#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int t;
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    //place pivot at right position
    int pivotindex=s+count;
    t=arr[pivotindex];      //swapping arr[pivotindex] with arr[s];
    arr[pivotindex]=arr[s];
    arr[s]=t;
    
    //left and right vaala part sambhalo
    int i=s;
    int j=e;
    
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            t=arr[i];     //swap arr[i] with arr[j]
            arr[i]=arr[j];
            arr[j]=t;
        }
        i++;
        j--;
    }
    return pivotindex;
}

void quicksort(int arr[],int s,int e){
    
    //base case
    if(s>=e){
        return ;
    }
    int p=partition(arr,s,e);
    
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main(){
    int arr[10]={2,4,2,1,3,7,5,8,9,0};
    int n=10;
    
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}