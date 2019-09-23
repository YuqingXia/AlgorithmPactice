import unittest
from palindrome_number import *


class TestLC9(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.solution = IsPalindrom()

    def test_case1(self):
        num = 121
        result = True
        self.assertEqual(self.solution.isPalindrom(num), result, "121 should be True")

    def test_case2(self):
        num = -121
        result = False
        self.assertEqual(self.solution.isPalindrom(num), result, "-121 should be False")

if __name__ == "__main__":
    unittest.main()