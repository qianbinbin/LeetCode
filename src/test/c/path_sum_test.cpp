#include <gtest/gtest.h>

extern "C" {
#include <path_sum.h>
}

TEST(leetcode_112, normal) {
    int nums[] = {5, 4, 8, 11, NTNODE, 13, 4, 7, 2, NTNODE, NTNODE,
                  NTNODE, NTNODE, NTNODE, 1};
    struct TreeNode *tree = tree_create(nums, sizeof(nums) / sizeof(nums[0]));
    tree_preorder_print(tree);
    tree_inorder_print(tree);
    EXPECT_TRUE(hasPathSum_112(tree, 22));
    tree_free(tree);
}
