# Commented on 21/07/24

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()  # Initialize a dummy node to form the resultant linked list
        first = dummy  # Pointer to track the current node in the result list
        carry = 0  # Initialize carry to 0

        # Traverse both lists until one or both lists are completely traversed
        while l1 and l2:
            total = l1.val + l2.val + carry  # Calculate the sum of values and carry
            if total >= 10:
                first.val = total % 10  # Store the single digit in the current node
                carry = 1  # Set carry for the next digit
            else:
                first.val = total  # Store the sum in the current node
                carry = 0  # Reset carry

            l1 = l1.next  # Move to the next node in l1
            l2 = l2.next  # Move to the next node in l2

            # Create a new node if there are more nodes in l1 or l2
            if l1 or l2:
                second = ListNode()
                first.next = second
                first = second

        # Determine which list still has remaining nodes
        remaining = l1 if l1 else l2

        # Traverse the remaining list and add its values
        while remaining:
            total = remaining.val + carry
            if total >= 10:
                first.val = total % 10
                carry = 1
            else:
                first.val = total
                carry = 0

            remaining = remaining.next

            # Create a new node if there are more nodes in the remaining list
            if remaining:
                second = ListNode()
                first.next = second
                first = second

        # If there's still a carry, create a new node with value 1
        if carry != 0:
            second = ListNode(1)
            first.next = second

        return dummy

def printList(node: ListNode):
    while node:
        print(node.val, end=" -> ")
        node = node.next
    print("None")

def main():
    # Create first list: 2 -> 4 -> 3
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    # Create second list: 5 -> 6 -> 4
    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    # Add the two numbers
    solution = Solution()
    result = solution.addTwoNumbers(l1, l2)

    # Print the result list
    printList(result)

if __name__ == "__main__":
    main()
