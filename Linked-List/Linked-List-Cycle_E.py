# Commented on 21/07/24

from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # if head is empty ,just return False
        if head:
            pass
        else:
            return False
        # slow and fast pointer technique
        slow = head
        fast = head.next

        while fast and fast.next:
            if slow == fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False

def main():
    # Create a cycle list: 1 -> 2 -> 3 -> 4 -> 2
    head = ListNode(1)
    second = ListNode(2)
    third = ListNode(3)
    fourth = ListNode(4)

    head.next = second
    second.next = third
    third.next = fourth
    fourth.next = second  # Create a cycle

    # Check for cycle
    solution = Solution()
    print(solution.hasCycle(head))  # Output: True

    # Create a non-cycle list: 1 -> 2 -> 3 -> 4 -> None
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)

    # Check for cycle
    print(solution.hasCycle(head))  # Output: False

if __name__ == "__main__":
    main()
