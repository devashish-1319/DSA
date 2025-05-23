#include<iostream>
#include<vector>
using namespace std;
//subset questions
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
    //base case
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }
        
    //exclude
    solve(nums, output, index+1, ans);
        
    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
        
}
    
vector<vector<int> > subsets(vector<int>& nums) {
        
    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
        
}
//subsequences questions
//powerset of string
void solve(string str,vector<string>& ans,int index,string output){
	if(index>=str.length()){
		if(output.length()>0){  //why this important
			ans.push_back(output);
		}
		return ;
	}
	//include
	output.push_back(str[index]);
	solve(str,ans,index+1,output);
	output.pop_back(); //backtrack important
	//exclude
	solve(str,ans,index+1,output);
}
vector<string> subsequences(string str){
	
	// Write your code here
	vector<string>ans;
	int index=0;
	string output="";
	solve(str,ans,index,output);
	return ans;
}
