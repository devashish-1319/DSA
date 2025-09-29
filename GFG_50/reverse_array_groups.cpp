#include<vector>
using namespace std;
class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i=i+k){
            int right=min(i+k,n);
            reverse(arr.begin()+i,arr.begin()+right);
        }
    }
};