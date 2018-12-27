#include "combinations.h"

#include <stdlib.h>
#include <string.h>

static int factorial(int n, int k) {
    int ret = 1;
    for (; k <= n; ++k)
        ret *= k;
    return ret;
}

static int combination(int n, int k) {
    k = k < n - k ? k : n - k;
    return factorial(n, n - k + 1) / factorial(k, 1);
}

static void combine_dfs(int n, int k, int begin,
                        int **combinations, int *c_size, int *col_sizes, int *path, int *path_size) {
    if (*path_size == k) {
        combinations[*c_size] = (int *) malloc(k * sizeof(int));
        memcpy(combinations[*c_size], path, k * sizeof(int));
        col_sizes[*c_size] = k;
        ++(*c_size);
        return;
    }
    for (int i = begin; i <= n; ++i) {
        path[(*path_size)++] = i;
        combine_dfs(n, k, i + 1, combinations, c_size, col_sizes, path, path_size);
        --(*path_size);
    }
}

int **combine_77_1(int n, int k, int **columnSizes, int *returnSize) {
    if (n < 1 || k < 1 || k > n || columnSizes == NULL || returnSize == NULL) return NULL;

    int capacity = combination(n, k);
    int **ret = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;
    *columnSizes = (int *) malloc(capacity * sizeof(int));

    int *path = (int *) malloc(k * sizeof(int));
    int path_size = 0;

    combine_dfs(n, k, 1, ret, returnSize, *columnSizes, path, &path_size);
    free(path);
    ret = (int **) realloc(ret, *returnSize * sizeof(int *));
    *columnSizes = (int *) realloc(*columnSizes, *returnSize * sizeof(int));
    return ret;
}
