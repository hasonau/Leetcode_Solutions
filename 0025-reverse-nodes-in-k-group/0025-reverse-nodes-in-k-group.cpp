class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;
        stack<ListNode*>s;

        while(head){
            ListNode* saveHead=head;
            ListNode* prev=nullptr;
            for(int i=0;i<k;i++){
                if(!head){
                    curr->next=saveHead;
                    return dummy->next;
                }
                s.push(head);
                head=head->next;
            }
            while(!s.empty()){
                curr->next=s.top();
                curr=curr->next;
                s.pop();
            }
        }
        return dummy->next;
    }
};