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
    ListNode *reverselinkedlist(ListNode *head){
        ListNode *prev=nullptr;
        ListNode *curr=head;
        while(curr){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // start point of second part of linkedlist is slow->next
        ListNode *curr = slow->next;
        slow->next=nullptr;
        ListNode *second = reverselinkedlist(curr);
        ListNode *first=head;

        // beaware of the linking
        while(second){
            ListNode *firstNext=first->next;
            first->next=second;
            ListNode *secondNext=second->next;
            second->next=firstNext;
            first=firstNext;
            second=secondNext;
        }
    }
};