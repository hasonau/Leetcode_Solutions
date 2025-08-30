class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nextNode;

        while(curr){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        return prev;
        
    }
};