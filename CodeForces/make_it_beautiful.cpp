#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool isUgly(vector<int>& a) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if(a[i] == sum){
            return true;
        }
        sum += a[i];
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool allequal=true;
        for(int i=1;i<n;i++){
            if(a[i]!=a[0]){
                allequal=false;
                break;
            }
        }
        if(allequal){
            cout<<"NO"<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        vector<int>result;
        int sum=0;
        vector<bool>used(n,false);
        for(int i=n-1;i>=0;i--){
            bool placed=false;
            for(int j=n-1;j>=0;j--){
                if(!used[j] && a[j]!=sum){
                    result.push_back(a[j]);
                    sum+=a[j];
                    used[j]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed){
                break;
            }
        }
        if(result.size()<n){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int x : result){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}