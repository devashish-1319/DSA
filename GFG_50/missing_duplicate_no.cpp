#include<vector>
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int duplicate=-1;
        int missing=-1;
        vector<int>freq(n+1,0);
        for(int num : arr){
            if(freq[num]==1){
                duplicate=num;
            }
            freq[num]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==0){
                missing=i;
                break;
            }
        }
        return {duplicate,missing};
    }
};