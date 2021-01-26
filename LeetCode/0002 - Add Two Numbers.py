# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        first = (l1.val + l2.val) % 10
        if l1.val + l2.val >= 10:
            carry = 1
            
        result = ListNode(val=first)
        
        next1 = l1.next
        next2 = l2.next
        nextNode = result
        
        while next1 is not None or next2 is not None:
            nextVal = carry
            if next1 is not None:
                nextVal += next1.val
                next1 = next1.next
            if next2 is not None:
                nextVal += next2.val
                next2 = next2.next
            
            carry = 1 if nextVal >= 10 else 0
            
            nextNode.next = ListNode(val = nextVal % 10)
            nextNode = nextNode.next
        
        if carry == 1:
            nextNode.next = ListNode(val = 1)
        
        return result
