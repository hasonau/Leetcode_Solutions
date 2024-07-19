# Code commented by GPT and given new good variable names, whereas code was originally written by Umair on 18.07.2024

# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        head=ListNode()
        tmp=head
        while list1 and list2 :
            if list1.val<=list2.val:
                tmp.next=list1
                list1=list1.next
            else:
                tmp.next=list2
                list2=list2.next
            tmp=tmp.next

        if list1:
            tmp.next=list1
        elif list2 :
            tmp.next=list2
        return head.next

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
