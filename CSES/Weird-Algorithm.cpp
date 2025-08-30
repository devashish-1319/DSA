#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector<long long int>ans;
    ans.push_back(n);
    while(n>=1){
        if(n==1){
            break;
        }
        if(n%2==0){
            n=n/2;
            ans.push_back(n);
        }
        else{
            n=(n*3)+1;
            ans.push_back(n);
        }
        
    }
    for(long long int i=0;i<(long long)ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}