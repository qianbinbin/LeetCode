#ifndef LEETCODE_WORD_SEARCH_H
#define LEETCODE_WORD_SEARCH_H

#include <stdbool.h>

/**
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * Example:
 *
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 */
bool exist_79(char **board, int boardRowSize, int boardColSize, char *word);

#endif //LEETCODE_WORD_SEARCH_H
