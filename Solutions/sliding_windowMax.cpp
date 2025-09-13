//#include<iostream>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;

        for(int i=0;i<nums.size();i++){
            //removing indices not in this window
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            //remove indices from the back
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            //window complete
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;

        //brute force
        vector<int>ans;
        for(int i=0;i<=nums.size()-k;i++){ //<= is used to include the last window
            int maxi=nums[i];
            for(int j=i;j<i+k;j++){ //j<=i+k-1
                maxi=max(maxi,nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};