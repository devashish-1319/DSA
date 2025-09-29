
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        unordered_set<int>seen;
        vector<int>ans;
        for(int num : arr){
            if(seen.find(num)==seen.end()){
                ans.push_back(num);
                seen.insert(num);
            }
        }
        return ans;
    }
};