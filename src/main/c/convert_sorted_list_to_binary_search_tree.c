#include "convert_sorted_list_to_binary_search_tree.h"

#include <stdlib.h>

static int list_len(struct ListNode *head) {
    int ret = 0;
    while (head != NULL) {
        ++ret;
        head = head->next;
    }
    return ret;
}

static struct TreeNode *sorted_list_to_bst(struct ListNode **p_node, int start, int end) {
    if (start == end) return NULL;

    int mid = start + (end - start) / 2;
    struct TreeNode *left = sorted_list_to_bst(p_node, start, mid);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = (*p_node)->val;
    root->left = left;
    *p_node = (*p_node)->next;
    root->right = sorted_list_to_bst(p_node, mid + 1, end);
    return root;
}

struct TreeNode *sortedListToBST_109_1(struct ListNode *head) {
    return sorted_list_to_bst(&head, 0, list_len(head));
}
