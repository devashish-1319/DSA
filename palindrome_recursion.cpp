#include<iostream>
using namespace std;

bool ispalindrome(string str,int i,int j){
    //base case
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        //recursive call
        return ispalindrome(str,i+1,j-1);
    }
}
int main(){
    
    string name="BookkooB";
    cout<<endl;
    
    bool ans=ispalindrome(name,0,name.length()-1);
    if(ans){
        cout<<"yes it is a palindome"<<endl;
    }
    else{
        cout<<"it is not a palindrome"<<endl;
    }
    return 0;
}