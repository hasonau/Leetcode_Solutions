class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode* dummy= new ListNode(0);
        ListNode* curr= dummy;

        while (l1 && l2){
            ListNode* temp=nullptr;
            if (l1->val<l2->val){
                temp = new ListNode(l1->val);
                l1=l1->next;
            }
            else{
                temp = new ListNode(l2->val);
                l2=l2->next;
            }
            curr->next=temp;
            curr=temp;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        vector<ListNode*>mergedLists;
        while(lists.size()>1){
            mergedLists={};
            for(int i =0; i<lists.size();i+=2){
                ListNode* list1=lists[i];
                ListNode* list2= (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(list1,list2));
            }
            lists=mergedLists;
        }

    return lists[0];
    }

};