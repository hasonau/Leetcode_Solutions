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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        int currSum=0;
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;
        while (l1 || l2 || carry){
            
            currSum = l1 ? l1->val : 0;
            currSum+=l2 ? l2->val :0;
            currSum+=carry;

            carry=currSum/10;
            currSum=currSum%10;
            ListNode* temp =new ListNode(currSum);
            curr->next=temp;
            curr=temp;

            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }

        return dummy->next;
    }
};