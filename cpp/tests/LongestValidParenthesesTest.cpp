#include "LongestValidParentheses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LongestValidParentheses, Solution32_1) {
  EXPECT_EQ(2, Solution32_1().longestValidParentheses("(()"));
  EXPECT_EQ(4, Solution32_1().longestValidParentheses(")()())"));
}

TEST(LongestValidParentheses, Solution32_2) {
  EXPECT_EQ(2, Solution32_2().longestValidParentheses("(()"));
  EXPECT_EQ(4, Solution32_2().longestValidParentheses(")()())"));
}

TEST(LongestValidParentheses, Solution32_3) {
  EXPECT_EQ(2, Solution32_3().longestValidParentheses("(()"));
  EXPECT_EQ(4, Solution32_3().longestValidParentheses(")()())"));
}
