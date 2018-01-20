#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <remove-duplicates-from-sorted-array-ii.h>
}

TEST(leetcode_80, empty) {
    int nums[] = {};
    print_array(nums, 0);
    EXPECT_EQ(removeDuplicates_80(nums, 0), 0);
}

TEST(leetcode_80, normal) {
    int nums[] = {0, 1, 1, 2, 5, 5, 5, 10, 10};
    print_array(nums, 9);
    int size = removeDuplicates_80(nums, 9);
    EXPECT_EQ(size, 8);
    print_array(nums, size);
}
