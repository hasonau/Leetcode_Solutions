//
// Created by muham on 18/07/2024.
//
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Your Solution class
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode;        // Pointer to temporarily hold the next node
        ListNode *prevNode = NULL; // Pointer to keep track of the previous node, initialized to NULL as the new end of the reversed list

        // Loop through the list until all nodes are processed
        while (head != NULL) {
            nextNode = head->next; // Save the next node
            head->next = prevNode; // Reverse the link: current node's next points to the previous node
            prevNode = head;       // Move prevNode to the current node (previous node for the next iteration)
            head = nextNode;       // Move head to the next node in the original list
        }

        head = prevNode; // At the end, prevNode will be pointing to the new head of the reversed list
        return head;     // Return the new head of the reversed list
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(9);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    // Reverse the list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Print the reversed list
    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Free the allocated memory
    while (reversedHead != NULL) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
