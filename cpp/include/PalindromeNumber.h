// Determine whether an integer is a palindrome. An integer is a palindrome when
// it reads the same backward as forward.
//
// Example 1:
//
// Input: 121
// Output: true
//
// Example 2:
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it
// becomes 121-. Therefore it is not a palindrome.
//
// Example 3:
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
// Follow up:
//
// Coud you solve it without converting the integer to a string?

#ifndef LEETCODECPP_PALINDROMENUMBER_H
#define LEETCODECPP_PALINDROMENUMBER_H

namespace lcpp {

class Solution9_1 {
public:
  bool isPalindrome(int x);
};

class Solution9_2 {
public:
  bool isPalindrome(int x);
};

} // namespace lcpp

#endif // LEETCODECPP_PALINDROMENUMBER_H