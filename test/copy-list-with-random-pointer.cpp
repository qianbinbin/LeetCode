#include <gtest/gtest.h>

extern "C" {
#include <copy-list-with-random-pointer.h>
}

TEST(leetcode_138, null) {
    EXPECT_TRUE(copyRandomList_138(NULL) == NULL);
}

// TODO: Implement normal test and print results.