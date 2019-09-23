import unittest
from add_two_number import Solution, ListNode

class TestAddTwoNumber(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.solution = Solution()

    def test_case1(self):
        link1 = ListNode(2)
        p = link1
        p.next = ListNode(4)
        p = p.next
        p.next = ListNode(3)

        link2 = ListNode(5)
        p = link2
        p.next = ListNode(6)
        p = p.next
        p.next = ListNode(4)

        res = ListNode(7)
        p = res
        p.next = ListNode(0)
        p = p.next
        p.next = ListNode(8)

        result = self.solution.addTwoNumbers(link1, link2)
        def check_if_node_equal(l1, l2):
            
            while True:
                if l1.val != l2.val:
                    return False
                if (l1.next != None) != (l2.next !=None):
                    return False
                elif l1.next is None:
                    break
                else:
                    l1 = l1.next
                    l2 = l2.next

            return True

        self.assertTrue(result)