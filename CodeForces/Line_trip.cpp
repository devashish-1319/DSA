#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int>path;
        path.push_back(0);
        for(int i=0;i<n;i++){
            path.push_back(a[i]);
        }
        path.push_back(x);
        for(int i=n-1;i>=0;i--){
            path.push_back(a[i]);
        }
        path.push_back(0);
        int maxgap=0;
        for(int i=1;i<path.size();i++){
            int gap=abs(path[i]-path[i-1]);
            maxgap=max(maxgap,gap);
        }
        maxgap=max(maxgap,2*(x - a[n - 1]));
        cout<<maxgap<<endl;
    }
    return 0;
}