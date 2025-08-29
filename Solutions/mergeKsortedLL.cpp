class Solution {
public:
    /*ListNode* convert(vector<int> &arr){
        if(arr.empty()){
            return NULL;
        }
        ListNode* head=new ListNode(arr[0]);
        ListNode* temp=head;
        for(int i=1;i<arr.size();i++){
            temp->next=new ListNode(arr[i]);
            temp=temp->next;
        }
        return head;
    }*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }
            temp->next=it.second;
            temp=temp->next;
        }
        return dummy->next;

        /*vector<int>arr;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                arr.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head=convert(arr);
        return head;*/
    }
};