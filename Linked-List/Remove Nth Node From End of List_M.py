from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast = head.next
        slow = head
        slow_counter = 1
        fast_counter = 2

        # Move the fast pointer two steps ahead and slow pointer one step ahead
        while fast and fast.next:
            slow = slow.next
            slow_counter += 1
            fast = fast.next.next
            fast_counter += 2

        # Check if the fast pointer reached the end of the list
        if not fast:
            fast_counter -= 1

        # Calculate the position to remove
        val = fast_counter - n + 1

        # If the position is the head of the list, return the next node
        if val == 1:
            return head.next

        # Adjust slow_counter to start from the beginning if necessary
        if slow_counter >= val:
            slow_counter = 1
            slow = head

        # Move to the node just before the one to be removed
        while slow_counter < val - 1:
            slow_counter += 1
            slow = slow.next

        # Remove the nth node from the end
        slow.next = slow.next.next

        # Return the modified list
        return head

# Main function to demonstrate the removeNthFromEnd function
def main():
    # Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    node5 = ListNode(5)
    node4 = ListNode(4, node5)
    node3 = ListNode(3, node4)
    node2 = ListNode(2, node3)
    head = ListNode(1, node2)

    # Calling removeNthFromEnd to remove the 2nd node from the end (4 in this case)
    new_head = Solution().removeNthFromEnd(head, 2)

    # Printing the modified list
    temp = new_head
    while temp is not None:
        print(temp.val, end=" -> " if temp.next else "")
        temp = temp.next

if __name__ == "__main__":
    main()

# Commented by GPT-4 on 19/7/2024
