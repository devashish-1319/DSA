#include<vector>
using namespace std;
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int j=0;
        //pehle non zero ko saamne leaaye
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[j]=arr[i];
                j++;
            }
        }
        //bache hue places mai 0n daal diye
        while(j<n){
            arr[j]=0;
            j++;
        }
        
    }
};