#include<vector>
using namespace std;
class Solution {
public:
    int findmax(vector<int> &piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long totaltime(vector<int> &piles,int h){
        long long total=0;
        for(int i=0;i<piles.size();i++){
            total+=((long long)piles[i]+h-1)/h;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        long long totalhrs=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            totalhrs=totaltime(piles,mid);
            if(totalhrs<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};