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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*>s;
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;

        while(head){
            ListNode* saveHead=head;
            for(int i=0;i<k;i++){
                if(!head) {
                    curr->next=saveHead;
                    return dummy->next;
                }
                s.push(head);
                head=head->next;
            }
            while(!s.empty()){
                ListNode* temp=s.top();
                s.pop();
                curr=curr->next=temp;
            }

        }
        
        curr->next=nullptr;
        return dummy->next;
    }
};