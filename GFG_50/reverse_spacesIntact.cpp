#include<string>
using namespace std;
class Solution {
  public:

    string reverseWithSpacesIntact(string s) {
        // code here.
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(s[l]==' '){
                l++;
                continue; //continue is important to keep spaces intact
            }
            if(s[r]==' '){
                r--;
                continue;
            }
            
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};