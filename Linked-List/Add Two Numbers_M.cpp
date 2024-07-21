//
// Created by muham on 21/07/2024.
//
// Code commented by GPT and given new, good variable names. Original code written by Umair on 21/7/24.

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();  // Initialize a dummy node to form the resultant linked list
        ListNode* first = dummy;  // Pointer to track the current node in the result list
        int carry = 0;  // Initialize carry to 0

        // Traverse both lists until one or both lists are completely traversed
        while (l1 != nullptr && l2 != nullptr) {
            int total = l1->val + l2->val + carry;  // Calculate the sum of values and carry
            if (total >= 10) {
                first->val = total % 10;  // Store the single digit in the current node
                carry = 1;  // Set carry for the next digit
            } else {
                first->val = total;  // Store the sum in the current node
                carry = 0;  // Reset carry
            }

            l1 = l1->next;  // Move to the next node in l1
            l2 = l2->next;  // Move to the next node in l2

            // Create a new node if there are more nodes in l1 or l2
            if (l1 != nullptr || l2 != nullptr) {
                ListNode* second = new ListNode();
                first->next = second;
                first = second;
            }
        }

        // Determine which list still has remaining nodes
        ListNode* remaining;
        if (l1 != nullptr) {
            remaining = l1;
        } else {
            remaining = l2;
        }

        // Traverse the remaining list and add its values
        while (remaining != nullptr) {
            int total = remaining->val + carry;
            if (total >= 10) {
                first->val = total % 10;
                carry = 1;
            } else {
                first->val = total;
                carry = 0;
            }

            remaining = remaining->next;

            // Create a new node if there are more nodes in the remaining list
            if (remaining != nullptr) {
                ListNode* second = new ListNode();
                first->next = second;
                first = second;
            }
        }

        // If there's still a carry, create a new node with value 1
        if (carry != 0) {
            ListNode* second = new ListNode(1);
            first->next = second;
        }

        return dummy;
    }
};

int main() {
    // Example usage
    Solution solution;

    // Create first list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result list
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
