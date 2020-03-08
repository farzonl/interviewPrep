import unittest
from submission import *

class TestSubmissions(unittest.TestCase):

    def test_is_sorted(self):
        self.assertTrue(is_sorted([1,2,3,4]))
        self.assertFalse(is_sorted([3,1,2,4]))

    def test_unsort(self):
        self.assertFalse(is_sorted(unsort([1,2,3,4])))

    def test_closest(self):
        self.assertEqual(closest([1,3,6,7,8,9],5),6)
        self.assertEqual(closest([1,3,4,7,8,9],5),4)
        self.assertEqual(closest([1,7,8,9],5), 7)

if __name__ == '__main__':
    unittest.main()