# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ret = ListNode(0)
        
        carry = 0
        p = ret

        while True:
            if l1.next is None: #assume l1 and l2 are equal
                break
            l1 = l1.next
            l2 = l2.next

            sum_val = l1.val + l2.val + carry
            carry = int(sum_val/10)
            
            p.next = ListNode(sum_val % 10)
            p = p.next
            
        return ret.next
