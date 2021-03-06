from unittest import TestCase

from leetcodepy.trapping_rain_water import *

solution1 = Solution1()

solution2 = Solution2()

solution3 = Solution3()

height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

expected = 6


class TestTrappingRainWater(TestCase):
    def test1(self):
        self.assertEqual(expected, solution1.trap(height))

    def test2(self):
        self.assertEqual(expected, solution2.trap(height))

    def test3(self):
        self.assertEqual(expected, solution3.trap(height))
