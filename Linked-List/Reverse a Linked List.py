from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        nextNode = None        # Pointer to temporarily hold the next node
        prevNode = None        # Pointer to keep track of the previous node, initialized to None as the new end of the reversed list

        # Loop through the list until all nodes are processed
        while head is not None:
            nextNode = head.next  # Save the next node
            head.next = prevNode  # Reverse the link: current node's next points to the previous node
            prevNode = head       # Move prevNode to the current node (previous node for the next iteration)
            head = nextNode       # Move head to the next node in the original list

        head = prevNode  # At the end, prevNode will be pointing to the new head of the reversed list
        return head      # Return the new head of the reversed list

# Helper function to print the list
def printList(head: Optional[ListNode]):
    current = head
    while current is not None:
        print(current.val, end=" ")
        current = current.next
    print()

# Main function to test the reverseList function
if __name__ == "__main__":
    # Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    # Print the original list
    print("Original list:")
    printList(head)

    # Reverse the list
    solution = Solution()
    reversedHead = solution.reverseList(head)

    # Print the reversed list
    print("Reversed list:")
    printList(reversedHead)
