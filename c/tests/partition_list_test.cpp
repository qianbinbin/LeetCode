#include <gtest/gtest.h>

extern "C" {
#include "partition_list.h"
}

TEST(partition_list_test, partition_86_1) {
    int nums[] = {1, 4, 3, 2, 5, 2};
    struct ListNode *head = list_create(nums, 6);
    list_print(head);
    head = partition_86_1(head, 3);
    list_print(head);
    list_free(head);
}