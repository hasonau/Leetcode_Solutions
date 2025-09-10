
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;

        while(fast && fast->next){
            //  this one line i was doing on end,i should be doing it on top,it caused 
            // me 20-30 minutes of pain
             fast=fast->next->next;

            ListNode* next= slow->next;
            slow->next=curr;
            curr=slow;
            slow=next;
           
        }
        ListNode* second=slow;
        ListNode* first=curr;
        int result=INT_MIN;

        while(second){
            result= max(result,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        
        return result;

    }

};