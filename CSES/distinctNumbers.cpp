#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    long long int n;
    cin>>n;

    vector<long long int>arr(n);
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<long long int>st(arr.begin(),arr.end());
    long long int ans=st.size();
    cout<<ans<<endl;
    return 0;
}