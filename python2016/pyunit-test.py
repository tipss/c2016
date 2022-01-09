'''
Demo how to use pyunit unitest modle
python -m unitest pyunit-test.py
'''

import unittest
from circles import circle_area
from math import pi

class  TestCircleArea(unittest.TestCase):
    # test areas when radius >= zero
    def test_area(self):   #test_ prefix is a must for every test function
       self.assertAlmostEqual(circle_area(1),   pi)
       self.assertAlmostEqual(circle_area(0),   0)
       self.assertAlmostEqual(circle_area(2.1), pi * 2.1**2)
