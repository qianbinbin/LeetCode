/*
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 *
 * https://leetcode.com/static/images/problemset/histogram.png
 *
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *
 * https://leetcode.com/static/images/problemset/histogram_area.png
 *
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 *
 * Example:
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 */

#ifndef LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#define LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H

int largestRectangleArea_84_1(int *heights, int heightsSize);

#endif //LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
