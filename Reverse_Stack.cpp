#include<stack>
using namespace std;
void insertatbottom(stack<int> &St, int x){
        if(St.empty()){
            St.push(x);
            return ;
        }
        int top=St.top();
        St.pop();
        insertatbottom(St,x);
        St.push(top);
    }
    void Reverse(stack<int> &St) {
        if(St.empty()){
            return ;
        }
        int top=St.top();
        St.pop();
        Reverse(St);
        insertatbottom(St,top);
    }