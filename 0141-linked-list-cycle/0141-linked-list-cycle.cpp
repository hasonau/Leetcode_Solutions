class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow=head;
        ListNode* fast = nullptr;

        // To avoid null pointer dereference
        if (head && head->next) fast = head->next->next;

        while(fast && fast->next){
            if(slow==fast){
                return true;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
        
    }
};