#include<vector>
using namespace std;
class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int product1=arr[n-1]*arr[n-2]*arr[n-3]; //all positives
        int product2=arr[0]*arr[1]*arr[n-1]; //two negatives and 1 positive
        
        return max(product1,product2);
    }
};