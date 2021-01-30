"""
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
"""
from collections import Counter
from typing import List


class Solution1:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result = []
        if not words:
            return result
        width = len(words[0])
        length = width * len(words)
        end = len(s) - length
        words = Counter(words)
        i = 0
        while i <= end:
            len_local = 0
            counter = Counter()
            for j in range(i, i + length, width):
                word = s[j:j + width]
                if word in words and counter[word] < words[word]:
                    len_local += width
                    counter[word] += 1
                else:
                    break
            if len_local == length:
                result.append(i)
            i += 1
        return result