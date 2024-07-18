# Code commented by GPT and given new good variable names, whereas code was originally written by Umair on 18.07.2024

# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # If one of the lists is empty, return the other list
        if not list1:
            return list2
        elif not list2:
            return list1
        else:
            pass

        # Initialize dummy head nodes for merged list
        head = ListNode(None)
        tmp = ListNode(None)
        count = 0

        # Merge the lists while both are non-empty
        while list1 and list2:
            if list1.val <= list2.val:
                if count == 0:
                    head = list1
                    count += 1
                tmp.next = list1
                tmp = list1
                list1 = list1.next
            else:
                if count == 0:
                    head = list2
                    count += 1
                tmp.next = list2
                tmp = list2
                list2 = list2.next

        # Attach the remaining elements of the non-empty list
        if list1:
            while list1:
                tmp.next = list1
                tmp = list1
                list1 = list1.next
        elif list2:
            while list2:
                tmp.next = list2
                tmp = list2
                list2 = list2.next
        else:
            return head

        return head

# Main function to test mergeTwoLists
if __name__ == "__main__":
    # Example usage
    # Creating two sorted linked lists
    # list1: 1 -> 2 -> 4
    list1 = ListNode(1)
    list1.next = ListNode(2)
    list1.next.next = ListNode(4)

    # list2: 1 -> 3 -> 4
    list2 = ListNode(1)
    list2.next = ListNode(3)
    list2.next.next = ListNode(4)

    solution = Solution()
    merged_list = solution.mergeTwoLists(list1, list2)

    # Printing the merged list
    current = merged_list
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")
