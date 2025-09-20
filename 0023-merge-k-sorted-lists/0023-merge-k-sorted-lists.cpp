class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if (!l2) return l1;

        if(!l1) return l2;
        ListNode* dummy=new ListNode();
        ListNode* curr=dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                curr->next=l1;
                curr=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                curr=l2;
                l2=l2->next;
            }
        }
        curr->next = l1 ? l1 : l2;
        return dummy->next;
    }

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // nullptr is [],so yeah do check this on very top
        if(lists.size()==0) return nullptr;
        vector<ListNode*>mergedLists;

        while(lists.size()>1){
            for(int i=0;i<lists.size();i+=2){
                ListNode* l1=lists[i];

                // this line is wrong
                // ListNode* l2= lists[i+1] ? lists[i+1] : nullptr;
                ListNode* l2= (i+1) < lists.size() ? lists[i+1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1,l2));
            }
            lists=mergedLists;
            // always remember doing this
            mergedLists.clear();
        }
    return lists[0];
    }
};