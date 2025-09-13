#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i; //next smaller element
                int pse;   //previous smaller element
                if(st.empty()){
                    pse=-1;
                }
                else{
                    pse=st.top(); 
                }
                maxarea=max(heights[element]*(nse-pse-1),maxarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse;
            if(st.empty()){
                pse=-1;
            }
            else{
                pse=st.top();
            }
            maxarea=max(maxarea,(nse-pse-1)*heights[element]);
        }
        return maxarea;
    }
};