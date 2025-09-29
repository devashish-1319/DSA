#include<vector>
using namespace std;
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos;
        vector<int>neg;
        for(int num : arr){
            if(num>=0){
                pos.push_back(num);
            }
            else{
                neg.push_back(num);
            }
        }
        vector<int>result;
        int i=0;
        int j=0;
        bool turnpositive=true;
        while(i<pos.size() && j<neg.size()){
            if(turnpositive){
                result.push_back(pos[i]);
                i++;
            }
            else{
                result.push_back(neg[j]);
                j++;
            }
            turnpositive=!turnpositive;
        }
        while(i<pos.size()){
            result.push_back(pos[i]);
            i++;
        }
        while(j<neg.size()){
            result.push_back(neg[j]);
            j++;
        }
        arr=result;
    }
};