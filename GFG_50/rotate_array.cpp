#include<vector>
using namespace std;
class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        //for left rotation this logic 
        reverse(arr.begin(),arr.begin()+d); //-1
        reverse(arr.begin()+d,arr.end());   //-2
        reverse(arr.begin(),arr.end());     //-3
        
        //for right rotation -> do step 3 at first, then step 1 and step 2
    }
};