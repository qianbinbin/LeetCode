#include "populating_next_right_pointers_in_each_node.h"

#include <stddef.h>

void connect_116_1(struct TreeLinkNode *root) {
    if (root == NULL) return;
    if (root->left != NULL) {
        root->left->next = root->right;
        if (root->next != NULL)
            root->right->next = root->next->left;
    }
    connect_116_1(root->left);
    connect_116_1(root->right);
}

void connect_116_2(struct TreeLinkNode *root) {
    if (root == NULL) return;
    struct TreeLinkNode *leading = root, *p = NULL;
    while (leading->left != NULL) {
        p = leading;
        leading = leading->left;
        while (p != NULL) {
            p->left->next = p->right;
            if (p->next != NULL)
                p->right->next = p->next->left;
            p = p->next;
        }
    }
}
