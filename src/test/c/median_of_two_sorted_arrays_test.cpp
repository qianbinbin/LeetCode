#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <median_of_two_sorted_arrays.h>
}

TEST(leetcode_4, empty) {
    int nums1[] = {1, 2, 3, 4};
    array_print(nums1, 4);
    int nums2[] = {};
    array_print(nums2, 0);
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4(nums1, 4, nums2, 0), 2.5);
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4(nums2, 0, nums1, 4), 2.5);
}

TEST(leetcode_4, normal) {
    int nums1[] = {5, 6, 7, 8, 9};
    array_print(nums1, 5);
    int nums2[] = {1, 2, 3, 4, 5, 6};
    array_print(nums2, 6);
    EXPECT_DOUBLE_EQ(findMedianSortedArrays_4(nums1, 5, nums2, 6), 5);
}