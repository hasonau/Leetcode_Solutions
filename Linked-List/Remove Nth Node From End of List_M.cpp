#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        int slow_counter = 1;
        int fast_counter = 2;

        // Move the fast pointer two steps ahead and slow pointer one step ahead
        while (fast && fast->next) {
            slow = slow->next;
            slow_counter++;
            fast = fast->next->next;
            fast_counter += 2;
        }

        // Check if the fast pointer reached the end of the list
        if (!fast) {
            fast_counter--;
        }

        // Calculate the position to remove
        int val = fast_counter - n + 1;

        // If the position is the head of the list, return the next node
        if (val == 1) return head->next;

        // Adjust slow_counter to start from the beginning if necessary
        if (slow_counter >= val) {
            slow_counter = 1;
            slow = head;
        }

        // Move to the node just before the one to be removed
        while (slow_counter < val - 1) {
            slow_counter++;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        // Return the modified list
        return head;
    }
};

// Main function to demonstrate the removeNthFromEnd function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4);
    node4->next = node5;
    ListNode* node3 = new ListNode(3);
    node3->next = node4;
    ListNode* node2 = new ListNode(2);
    node2->next = node3;
    ListNode* head = new ListNode(1);
    head->next = node2;

    // Calling removeNthFromEnd to remove the 2nd node from the end (4 in this case)
    Solution solution;
    ListNode* new_head = solution.removeNthFromEnd(head, 2);

    // Printing the modified list
    ListNode* temp = new_head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;

    // Freeing allocated memory
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}

// Commented by GPT-4 on 19/7/2024
