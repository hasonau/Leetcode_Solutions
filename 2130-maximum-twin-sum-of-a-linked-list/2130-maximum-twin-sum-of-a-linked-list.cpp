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
        ListNode* fast=head->next;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;

        while(fast->next){
            ListNode* temp=slow->next;
            slow->next=curr;
            curr=slow;
            slow=temp;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=curr;
        int result=0;
        while(fast){
            result=max(fast->val+slow->val,result);
            slow=slow->next;
            fast=fast->next;
        }
        return result;
    }
};