#include<string>
using namespace std;
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        s1.append(s1);
        int i=0;
        int j=0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j]){
                i++;
            }
            else if(s1[i]==s2[j]){
                i++;
                j++;
            }
            if(j==s2.size()){
                return true;
            }
        }
        return false;
    }
};