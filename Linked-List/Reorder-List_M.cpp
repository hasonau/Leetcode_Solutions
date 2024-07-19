#include <iostream>
#include <deque>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // Initialize an empty deque to store the nodes
        deque<ListNode*> mydeque;
        ListNode* temp = head;

        // Traverse the list and add each node to the deque
        while (temp != nullptr) {
            mydeque.push_back(temp);
            temp = temp->next;
        }

        int count = 1;
        ListNode dummy(0);  // Temporary dummy node to start the new list
        temp = &dummy;

        // Reorder the list by alternating between nodes from the front and back of the deque
        while (!mydeque.empty()) {
            ListNode* node;
            if (count % 2 == 1) {
                node = mydeque.front();  // Get a node from the front
                mydeque.pop_front();
            } else {
                node = mydeque.back();  // Get a node from the back
                mydeque.pop_back();
            }
            count++;
            temp->next = node;  // Link the current node to the new list
            temp = node;  // Move to the next node
        }

        temp->next = nullptr;  // Ensure the last node points to nullptr to terminate the list
    }
};

// Main function to demonstrate the reorderList function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4
    ListNode* node4 = new ListNode(4);
    ListNode* node3 = new ListNode(3);
    node3->next = node4;
    ListNode* node2 = new ListNode(2);
    node2->next = node3;
    ListNode* head = new ListNode(1);
    head->next = node2;

    // Calling reorderList
    Solution().reorderList(head);

    // Printing the reordered list
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;

    // Freeing allocated memory
//    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}

// Commented by GPT-4 on 19/7/2024
