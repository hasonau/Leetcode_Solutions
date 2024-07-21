//
// Created by muham on 21/07/2024.
//
//# Commented on 21/07/24
// Commented on 21/07/24

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // if head is empty, just return False
        if (!head) {
            return false;
        }
        // slow and fast pointer technique
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

int main() {
    // Create a cycle list: 1 -> 2 -> 3 -> 4 -> 2
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // Create a cycle

    // Check for cycle
    Solution solution;
    std::cout << std::boolalpha << solution.hasCycle(head) << std::endl;  // Output: true

    // Create a non-cycle list: 1 -> 2 -> 3 -> 4 -> nullptr
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Check for cycle
    std::cout << std::boolalpha << solution.hasCycle(head) << std::endl;  // Output: false

    return 0;
}
