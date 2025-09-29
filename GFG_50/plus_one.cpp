#include<vector>
using namespace std;
class Solution {
  public:
    vector<int> addOne(vector<int>& arr) {
        // code here
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(arr[i]<9){
                arr[i]=arr[i]+1;
                return arr;
            }
            arr[i]=0;
        }
        vector<int>result(n+1,0);
        result[0]=1;
        return result;
    }
};