#include<stack>
using namespace std;
class MyQueue {
private:
    stack<int>s1;
    stack<int>s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int temp1=s1.top();
            s2.push(temp1);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            int temp2=s2.top();
            s1.push(temp2);
            s2.pop();
        }
    }
    
    int pop() {
        int temp=s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};