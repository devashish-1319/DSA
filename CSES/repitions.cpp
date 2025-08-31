#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n=s.size();
    int maxlen=1;
    int currlen=1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            currlen++;
            maxlen=max(maxlen,currlen);
        }
        else{
            currlen=1;
        }
    }
    cout<<maxlen<<endl;
    return 0;
}