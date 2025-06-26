#include <climits>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int operations=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            cout<<operations<<endl;
            return 0;
        }
    }
    sort(a.begin(),a.end());
    int smallestpositive=INT_MAX;
    int largestnegative=INT_MIN;
    for(int i=0;i<n;i++){
        if(a[i]>0 && a[i]<smallestpositive){
            smallestpositive=a[i];
        }
        if(a[i]<0 && a[i]>largestnegative){
            largestnegative=a[i];
        }
    }
    if(largestnegative==INT_MIN){
        operations=smallestpositive;
        cout<<operations<<endl;
        return 0;
    }
    if(smallestpositive==INT_MAX){
        operations=(-1)*largestnegative;
        cout<<operations<<endl;
        return 0;
    }
    largestnegative=(-1)*largestnegative;
    operations = abs(min(largestnegative,smallestpositive));
    cout<<operations<<endl;
    return 0;  
}