#include <gtest/gtest.h>

extern "C" {
#include <best_time_to_buy_and_sell_stock_iii.h>
}

TEST(leetcode_123_1, normal) {
    int prices1[] = {3, 3, 5, 0, 0, 3, 1, 4};
    EXPECT_EQ(maxProfit_123_1(prices1, 8), 6);
    int prices2[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfit_123_1(prices2, 5), 4);
    int prices3[] = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit_123_1(prices3, 5), 0);
}

TEST(leetcode_123_2, normal) {
    int prices1[] = {3, 3, 5, 0, 0, 3, 1, 4};
    EXPECT_EQ(maxProfit_123_2(prices1, 8), 6);
    int prices2[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(maxProfit_123_2(prices2, 5), 4);
    int prices3[] = {7, 6, 4, 3, 1};
    EXPECT_EQ(maxProfit_123_2(prices3, 5), 0);
}