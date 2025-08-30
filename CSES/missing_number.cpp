#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    for(int i=1;i<=n-1;i++){
        if(arr[i]!=i){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
} 