// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
// But the following [1,2,2,null,3,null,3] is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.

#ifndef LEETCODECPP_SYMMETRICTREE_H
#define LEETCODECPP_SYMMETRICTREE_H

#include "TreeNode.h"

namespace lcpp {

class Solution101_1 {
public:
  bool isSymmetric(TreeNode *root);
};

class Solution101_2 {
public:
  bool isSymmetric(TreeNode *root);
};

}

#endif //LEETCODECPP_SYMMETRICTREE_H
