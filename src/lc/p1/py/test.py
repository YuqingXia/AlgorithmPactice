import unittest
from two_sum import Solution

class TestTwoSum(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.solution = Solution()

    def test_case1(self):
        l = [2, 7, 11, 15]
        target = 9

        ret = [0, 1]
        self.assertEqual(self.solution.two_sum(l, target), ret)

    def test_two_sum_1(self):
        l = [2, 7, 11, 15]
        target = 9
        ret = [0, 1]
        self.assertEqual(self.solution.two_sum_1(l, target), ret)