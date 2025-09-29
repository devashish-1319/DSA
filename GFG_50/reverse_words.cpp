#include<vector>
#include<string>
using namespace std;
class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        //string stream is the best approach for this type of questions
        for(char &c : s){
            if(c=='.'){
                c=' ';
            }
        }
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss >> word){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());
        string result="";
        for(int i=0;i<words.size();i++){
            result+=words[i];
            if(i<words.size()-1){ //jab tak last word nahi aata tab tab dots daalo
                result+='.';
            }
        }
        return result;
    }
};