#include<iostream>
using namespace std;
#include<stack>
class Solution {
public:
    bool isValid(string string) {
        stack<char>s;
        for (int i=0;i<string.length();i++){
            char ch=string[i];
        
            if(ch=='(' || ch== '{' || ch=='['){
                s.push(ch);
            }
            else{
                if(!s.empty()){
                    char top=s.top();
                    if((ch==')' && top=='(')||(ch=='}' && top=='{')||(ch==']' && top=='[')){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(s.empty()){
                return true;
        }
        else{
            return false;
        }           
    }
};