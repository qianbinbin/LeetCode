#ifndef LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
#define LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H

#include <common.h>

/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * Return the following binary tree:
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *buildTree_106(int *inorder, int inorderSize, int *postorder, int postorderSize);

#endif //LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
