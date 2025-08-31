
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* left=dummy;
        ListNode* right=head;

        for (int i=0;i<n;i++){
            right=right->next;
        }
        while(right){
            left=left->next;
            right=right->next;
        }

         left->next = left->next->next;

        return dummy->next;

    }
};