#include "binary_tree_level_order_traversal_ii.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void pre_order(struct TreeNode *root, int level,
                      int ***lists, int *size, int *capacity, int **col_sizes, int **col_caps) {
    if (root == NULL) return;
    if (level == *size) {
        if (*size >= *capacity) {
            int new_cap = *capacity << 1;
            *lists = (int **) realloc(*lists, new_cap * sizeof(int *));
            memset(*lists + *capacity, 0, *capacity * sizeof(int *));
            *col_sizes = (int *) realloc(*col_sizes, new_cap * sizeof(int));
            memset(*col_sizes + *capacity, 0, *capacity * sizeof(int));
            *col_caps = (int *) realloc(*col_caps, new_cap * sizeof(int));
            memset(*col_caps + *capacity, 0, *capacity * sizeof(int));
            *capacity = new_cap;
        }
        if ((*lists)[*size] == NULL) {
            (*col_caps)[*size] = 8;
            (*lists)[*size] = (int *) malloc(8 * sizeof(int));
            ++*size;
        }
    }
    int **l = *lists + level;
    int *col_size = *col_sizes + level;
    int *col_cap = *col_caps + level;
    if (*col_size >= *col_cap) {
        *col_cap *= 2;
        *l = (int *) realloc(*l, *col_cap * sizeof(int));
    }
    (*l)[(*col_size)++] = root->val;
    pre_order(root->left, level + 1, lists, size, capacity, col_sizes, col_caps);
    pre_order(root->right, level + 1, lists, size, capacity, col_sizes, col_caps);
}

int **levelOrderBottom_107_1(struct TreeNode *root, int **columnSizes, int *returnSize) {
    if (root == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    int capacity = 8;
    int **ret = (int **) calloc(capacity, sizeof(int *));
    *returnSize = 0;
    *columnSizes = (int *) calloc(capacity, sizeof(int));
    int *col_caps = (int *) calloc(capacity, sizeof(int));

    pre_order(root, 0, &ret, returnSize, &capacity, columnSizes, &col_caps);

    ret = (int **) realloc(ret, *returnSize * sizeof(int *));
    for (int i = 0; i < *returnSize; ++i) ret[i] = (int *) realloc(ret[i], ((*columnSizes)[i] * sizeof(int)));
    *columnSizes = (int *) realloc(*columnSizes, *returnSize * sizeof(int));
    free(col_caps);

    const int half = *returnSize / 2;
    int *p_tmp, tmp;
    for (int i = 0; i < half; ++i) {
        p_tmp = ret[i];
        ret[i] = ret[*returnSize - 1 - i];
        ret[*returnSize - 1 - i] = p_tmp;
        tmp = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[*returnSize - 1 - i];
        (*columnSizes)[*returnSize - 1 - i] = tmp;
    }
    return ret;
}

typedef struct Queue {
    void **elements;
    int size;
    int capacity;
    int head;
    int tail;
} queue;

static queue *queue_create() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->elements = (void **) calloc(16, sizeof(void *));
    q->size = 0;
    q->capacity = 16;
    q->head = 0;
    q->tail = 0;
    return q;
}

static void queue_offer(queue *q, void *e) {
    int t = q->tail;
    q->elements[t] = e;
    ++q->size;
    q->tail = (t + 1) & (q->capacity - 1);
    if (q->tail == q->head) {
        int n = q->capacity;
        int new_cap = n << 1;
        void **a = (void **) calloc(new_cap, sizeof(void *));
        int left = q->head, right = n - left;
        memcpy(a, q->elements + left, right * sizeof(void *));
        memcpy(a + right, q->elements, left * sizeof(void *));
        free(q->elements);
        q->elements = a;
        q->capacity = new_cap;
        q->head = 0;
        q->tail = n;
    }
}

static void *queue_poll(queue *q) {
    int h = q->head;
    if (h == q->tail) return NULL;
    void *ret = q->elements[h];
    q->elements[h] = NULL;
    q->head = (h + 1) & (q->capacity - 1);
    --q->size;
    return ret;
}

static bool queue_empty(queue *q) {
    return q->size == 0;
}

static void queue_free(queue *q) {
    free(q->elements);
    free(q);
}

int **levelOrderBottom_107_2(struct TreeNode *root, int **columnSizes, int *returnSize) {
    if (root == NULL || columnSizes == NULL || returnSize == NULL) return NULL;

    int capacity = 8;
    int **ret = (int **) calloc(capacity, sizeof(int *));
    *columnSizes = (int *) calloc(capacity, sizeof(int));
    int *col_caps = (int *) calloc(capacity, sizeof(int));
    *returnSize = 0;

    queue *q = queue_create();
    queue_offer(q, root);
    while (!queue_empty(q)) {
        if (*returnSize >= capacity) {
            int new_cap = capacity << 1;
            ret = (int **) realloc(ret, new_cap * sizeof(int *));
            memset(ret + capacity, 0, capacity * sizeof(int *));
            *columnSizes = (int *) realloc(*columnSizes, new_cap * sizeof(int));
            memset(*columnSizes + capacity, 0, capacity * sizeof(int));
            col_caps = (int *) realloc(col_caps, new_cap * sizeof(int));
            memset(col_caps + capacity, 0, capacity * sizeof(int));
            capacity = new_cap;
        }
        const int size = q->size;
        for (int i = 0; i < size; ++i) {
            if (ret[*returnSize] == NULL) {
                ret[*returnSize] = (int *) malloc(8 * sizeof(int));
                col_caps[*returnSize] = 8;
            }
            if ((*columnSizes)[*returnSize] >= col_caps[*returnSize]) {
                col_caps[*returnSize] *= 2;
                ret[*returnSize] = (int *) realloc(ret[*returnSize], col_caps[*returnSize] * sizeof(int));
            }
            struct TreeNode *n = queue_poll(q);
            ret[*returnSize][(*columnSizes)[*returnSize]++] = n->val;
            if (n->left != NULL) queue_offer(q, n->left);
            if (n->right != NULL) queue_offer(q, n->right);
        }
        ++(*returnSize);
    }
    queue_free(q);
    ret = (int **) realloc(ret, *returnSize * sizeof(int *));
    for (int i = 0; i < *returnSize; ++i) ret[i] = (int *) realloc(ret[i], (*columnSizes)[i] * sizeof(int));
    *columnSizes = (int *) realloc(*columnSizes, *returnSize * sizeof(int));
    free(col_caps);

    const int half = *returnSize / 2;
    int *p_tmp, tmp;
    for (int i = 0; i < half; ++i) {
        p_tmp = ret[i];
        ret[i] = ret[*returnSize - 1 - i];
        ret[*returnSize - 1 - i] = p_tmp;
        tmp = (*columnSizes)[i];
        (*columnSizes)[i] = (*columnSizes)[*returnSize - 1 - i];
        (*columnSizes)[*returnSize - 1 - i] = tmp;
    }
    return ret;
}
