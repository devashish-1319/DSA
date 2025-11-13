//#include<bits/stdc++.h>
#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int>q;
    vector<int>ans;

    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        q.push(q.front());
        q.pop();

        ans.push_back(q.front());
        q.pop();
    }

    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
