
#include<iostream>
using namespace std;

int binarysearch(int n){
    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        int square=mid*mid;
        if(square==n){
            return mid;
        }
        else if(square>n){
            e=mid-1;
        }
        else if(square<n){
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter your number"<<endl;
    cin>>n;

    cout<<"sq root is: "<<binarysearch(n)<<endl;
}