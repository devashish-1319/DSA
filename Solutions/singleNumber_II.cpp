#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bitindex=0;bitindex<32;bitindex++){
            int count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] & (1<<bitindex)){
                    count++;
                }
            }
            if(count%3==1){
                ans=ans | (1<<bitindex);
            }
        }
        return ans;
    }
};