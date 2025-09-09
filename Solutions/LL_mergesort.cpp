#include <cstddef>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* merge(Node* l1,Node* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        Node* result=NULL;
        if(l1->data<=l2->data){
            result=l1;
            result->next=merge(l1->next,l2);
        }
        else{
            result=l2;
            result->next=merge(l1,l2->next);
        }
        return result;
    }
    Node* getmiddle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        // code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* middle=getmiddle(head);
        Node* nexthalf=middle->next;
        middle->next=NULL;
        
        Node* left=mergeSort(head);  //left half check
        Node* right=mergeSort(nexthalf);  //right half check
        
        return merge(left,right);
        
    }
};