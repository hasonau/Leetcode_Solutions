from collections import deque
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # Initialize an empty deque to store the nodes
        mydeque = deque()
        temp = head

        # Traverse the list and add each node to the deque
        while temp is not None:
            mydeque.append(temp)
            temp = temp.next

        count = 1
        temp = ListNode()  # Temporary dummy node to start the new list

        # Reorder the list by alternating between nodes from the front and back of the deque
        while mydeque:
            if count % 2 == 1:
                node = mydeque.popleft()  # Get a node from the front
            else:
                node = mydeque.pop()  # Get a node from the back
            count += 1
            temp.next = node  # Link the current node to the new list
            temp = node  # Move to the next node

        temp.next = None  # Ensure the last node points to None to terminate the list

# Example usage
if __name__ == "__main__":
    # Creating a linked list: 1 -> 2 -> 3 -> 4
    node4 = ListNode(4)
    node3 = ListNode(3, node4)
    node2 = ListNode(2, node3)
    head = ListNode(1, node2)

    # Calling reorderList
    Solution().reorderList(head)

    # Print the reordered list to verify
    temp = head
    while temp is not None:
        print(temp.val, end=" ->" if temp.next else "\n")
        temp = temp.next

# Commented by GPT-4 on 19/7/2024
