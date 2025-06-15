#include<iostream>
#include<vector>


using namespace std;
bool isSorted(vector<int> &a){
    for(int i=1;i<a.size();i++){
        if(a[i]<a[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(k==1){
            if(isSorted(a)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl; //for k>1, always sortable
        }
    }
    return 0;
}