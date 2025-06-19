#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        vector<int>x(n);
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        int minx=*min_element(x.begin(),x.end());
        int maxx=*max_element(x.begin(),x.end());
        int steps=max(s,maxx)-min(s,minx);
        cout<<steps<<endl;
    }
    return 0;
}