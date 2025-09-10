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


        while(l1 || l2 || carry){
            int val1= l1 ? l1->val :0;
            int val2= l2 ? l2->val :0;

            currSum=val1+val2+carry;
            carry=currSum/10;
            currSum= currSum%10;

            ListNode* temp=new ListNode(currSum);
            curr->next=temp;
            curr=temp;
            l1 = l1?l1->next:nullptr;
            l2= l2? l2->next:nullptr;

        }

        return dummy->next;
    }
};