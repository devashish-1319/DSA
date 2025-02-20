#include<iostream>
using namespace std;

int findIntersection(int arr1[],int n,int arr2[],int m){
    int i=0;
    int j=0;
    int ans;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            ans=arr2[i];
            i++;
            j++;
        }
        if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}
int main(){
    int arr1[6]={1,3,5,7,9,80};
    int n=6;

    int arr2[6]={1,4,6,8,9,70};
    int m=6;

    cout<<"intersection is "<<findIntersection(arr1,n,arr2,m)<<endl;
    return 0;
}