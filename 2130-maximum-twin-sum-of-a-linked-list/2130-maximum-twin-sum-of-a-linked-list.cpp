/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        stack<ListNode*> savedStack;

        while(fast){
            savedStack.push(slow);
            slow=slow->next;
            fast=fast->next->next;
        }
        int maxTwinSum=0;
        while(slow){
           maxTwinSum =max(maxTwinSum, slow ->val + savedStack.top()->val);
           savedStack.pop();
           slow=slow->next;
        }
        return maxTwinSum;
    }
};