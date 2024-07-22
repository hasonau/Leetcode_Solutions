//
// Created by muham on 22/07/2024.
//
#include <vector>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* tmp = &dummy;

        // Merge the lists while both lists have nodes
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }

        // Attach the remaining nodes, if any
        if (list1) {
            tmp->next = list1;
        } else if (list2) {
            tmp->next = list2;
        }

        return dummy.next;
    }

    // Function to merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }

        vector<ListNode*> newlist;
        int count = lists.size() % 2; // Check if the number of lists is odd

        int i = 0;
        int end_index = (count == 1) ? lists.size() - 1 : lists.size();

        // Merge lists in pairs and store in newlist
        while (i < end_index) {
            ListNode* merged = mergeTwoLists(lists[i], lists[i + 1]);
            newlist.push_back(merged);
            i += 2;
        }

        // If the original list count was odd, append the last list to newlist
        if (count == 1) {
            newlist.push_back(lists[lists.size() - 1]);
        }

        // Recursively merge the newlist
        return mergeKLists(newlist);
    }
};

// Commented and today's date is 22/7/24

// Main function to test the implementation
int main() {
    // Example usage
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};

    Solution solution;
    ListNode* merged_head = solution.mergeKLists(lists);

    // Print merged linked list
    while (merged_head) {
        std::cout << merged_head->val << " -> ";
        merged_head = merged_head->next;
    }
    std::cout << "None" <<std::endl;

    return 0;
}

