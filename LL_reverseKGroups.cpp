//when left out nodes should remain as it is
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        ListNode* cursor=head;
        for(int i=0;i<k;i++){
            if(cursor==NULL){
                return head;
            }
            cursor=cursor->next;
        }
        //reverse first K nodes
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count=0;

        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        //recursion
        if(head!=NULL){
            head->next=reverseKGroup(next,k);
        }
        //return head of recursive list
        return prev;
    }
};


//when left out nodes must also be reversed.
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL || k<=1){
            return head;
        }
        Node* cursor=head;
        int count=0;
        while(cursor!=NULL && count<k){
            cursor=cursor->next;
            count++;
        }
        //for(int i=0;i<k;i++){
        //    if(cursor==NULL){
        //        return head;
        //    }
        //    cursor=cursor->next;
        //}
        Node* forward=NULL;
        Node* curr=head;
        Node* prev=NULL;
        int i=0;
        while(curr!=NULL && i<count){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            i++;
        }
        //recursion
        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }
        return prev;
    }
};