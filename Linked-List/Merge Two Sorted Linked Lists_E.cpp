// Code commented by GPT and given new good variable names, whereas code was originally written by Umair on 18.07.2024

#include <iostream>
#include <limits> // for std::numeric_limits

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If one of the lists is empty, return the other list
        if (!list1) return list2;
        if (!list2) return list1;

        // Initialize dummy head node for merged list
        ListNode* head = new ListNode(std::numeric_limits<int>::max());
        ListNode* tmp = new ListNode(std::numeric_limits<int>::max());
        int count = 0;

        // Merge the lists while both are non-empty
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                if (count == 0) {
                    head = list1;
                    count++;
                }
                tmp->next = list1;
                tmp = list1;
                list1 = list1->next;
            } else {
                if (count == 0) {
                    head = list2;
                    count++;
                }
                tmp->next = list2;
                tmp = list2;
                list2 = list2->next;
            }
        }

        // Attach the remaining elements of the non-empty list
        if (list1) {
            while (list1) {
                tmp->next = list1;
                tmp = list1;
                list1 = list1->next;
            }
        } else if (list2) {
            while (list2) {
                tmp->next = list2;
                tmp = list2;
                list2 = list2->next;
            }
        } else {
            return head;
        }

        return head;
    }
};

int main() {
    // Example usage
    // Creating two sorted linked lists
    // list1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // list2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Printing the merged list
    ListNode* current = mergedList;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;

    return 0;
}
