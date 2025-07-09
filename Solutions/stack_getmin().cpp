#include <stack>
#include <climits>
using namespace std;
class MinStack {
public:
    stack<int> s;
    stack<int> minStack;

    MinStack() {
        // No need to initialize anything specific here
    }
    
    void push(int val) {
        s.push(val);
        // Push the minimum value onto the minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    int pop() {
        if (s.empty()) {
            return -1;  // Return -1 or handle error if stack is empty
        }
        
        int topValue = s.top();
        s.pop();
        if (topValue == minStack.top()) {
            minStack.pop();
        }
        
        return topValue;
    }
    
    int top() {
        if (s.empty()) {
            return -1;  // Return -1 or handle error if stack is empty
        }
        
        return s.top();
    }
    
    int getMin() {
        if (minStack.empty()) {
            return -1;  // Return -1 or handle error if minStack is empty
        }
        return minStack.top();
    }
};