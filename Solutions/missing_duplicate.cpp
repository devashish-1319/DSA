#include<vector>
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int missing=-1;
        int duplicate=-1;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        if(arr[0]!=1){
            missing=1;
        }
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                duplicate=arr[i];
            }
            else if(arr[i]!=arr[i-1]+1 && missing==-1){
                missing=arr[i-1]+1;
            }
        }
        if(missing==-1){
            missing=n;
        }
        return {duplicate,missing};
    }
};