#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;


int maxfrequency(vector<int> &arr,int n){
    unordered_map<int,int>count;
    int maxfreq=0;
    int maxans=0;

    for(int i=0;i<n;i++){
        count[arr[i]]++;
        maxfreq=max(maxfreq,count[arr[i]]);
    }
    for(int i=0;i<n;i++){
        if(maxfreq==count[arr[i]]){
            maxans=arr[i];
            break;
        }
    }
    return maxans;

}