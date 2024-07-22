# Definition for singly-linked list.
from typing import List,Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    # Function to merge two sorted linked lists
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        # Initialize a dummy node to form the merged list
        head = ListNode()
        tmp = head

        # Merge the lists while both lists have nodes
        while list1 and list2:
            if list1.val <= list2.val:
                tmp.next = list1
                list1 = list1.next
            else:
                tmp.next = list2
                list2 = list2.next
            tmp = tmp.next

        # Attach the remaining nodes, if any
        if list1:
            tmp.next = list1
        elif list2:
            tmp.next = list2

        return head.next

    # Function to merge k sorted linked lists
    # This function uses a divide and conquer approach, merging lists in pairs recursively
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]

        newlist = []
        count = len(lists) % 2  # Check if the number of lists is odd

        i = 0
        end_index = len(lists) - 1 if count == 1 else len(lists)

        # Merge lists in pairs and store in newlist
        while i < end_index:
            merged = self.mergeTwoLists(lists[i], lists[i + 1])
            newlist.append(merged)
            i += 2

        # If the original list count was odd, append the last list to newlist
        if count == 1:
            newlist.append(lists[len(lists) - 1])

        # Recursively merge the newlist
        result = self.mergeKLists(newlist)
        return result

# Commented and today's date is 22/7/24

# Main function to test the implementation
if __name__ == "__main__":
    # Example usage
    lists = [
        ListNode(1, ListNode(4, ListNode(5))),
        ListNode(1, ListNode(3, ListNode(4))),
        ListNode(2, ListNode(6))
    ]
    solution = Solution()
    merged_head = solution.mergeKLists(lists)

    # Print merged linked list
    while merged_head:
        print(merged_head.val, end=" -> ")
        merged_head = merged_head.next
    print("None")
