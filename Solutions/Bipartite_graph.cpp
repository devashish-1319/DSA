//brute force approach
#include<iostream>
using namespace std;

bool check(int start,int V,vector<int>adj[],int color[]){
    queue<int>q;
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i : adj[node]){
            if(color[i]==1){
                color[i]!=color[node]{
                    q.push(i);
                }
            }
            else if(color[i]==color[node]){
                return false;
            }
        }
    }
    return true;
}