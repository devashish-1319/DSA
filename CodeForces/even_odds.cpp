#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            a.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2==0){
            a.push_back(i);
        }
    }
    int answer=a[k-1];
    cout<<answer<<endl;
}