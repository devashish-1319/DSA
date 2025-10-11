#include<string>
using namespace std;
class Solution {
  public:
    
    string removeUtil(string &s) {
        // code here
        if(s.size()<=1){
            return s;
        }
        string result="";
        bool removed=false;
        for(int i=0;i<s.size();){ //yaha increment nahi hai : observe
            if(i+1<s.size() && s[i]==s[i+1]){
                removed=true;
                char ch=s[i];
                while(i<s.size() && s[i]==ch){
                    i++;
                }
            }
            else{
                result.push_back(s[i]);
                i++; //this is important why ?
            }
        }
        if(!removed){
            return result;
        }
        return removeUtil(result);
    }
};