#include<iostream>
using namespace std;
// * Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        dummy->next=head;

        while(head!=NULL && head->next!=NULL){
            ListNode* first=head;
            ListNode* second=head->next;
            
            //swap
            prev->next=second;
            first->next=second->next;
            second->next=first;

            //move the pointers
            prev=first;
            head=first->next;
        }
        return dummy->next;
    }
};