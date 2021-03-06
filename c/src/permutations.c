#include "permutations.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void permute_dfs(int *nums, int nums_size,
                        int **permutations, int *size, int *path, int *path_size, bool *visited) {
    if (*path_size == nums_size) {
        permutations[*size] = (int *) malloc((*path_size) * sizeof(int));
        memcpy(permutations[*size], path, (*path_size) * sizeof(int));
        ++(*size);
        return;
    }
    for (int i = 0; i < nums_size; ++i) {
        if (visited[i]) continue;
        path[(*path_size)++] = nums[i];
        visited[i] = true;
        permute_dfs(nums, nums_size, permutations, size, path, path_size, visited);
        visited[i] = false;
        --(*path_size);
    }
}

static int factorial(int n) {
    int ret = 1;
    for (int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}

int **permute_46_1(int *nums, int numsSize, int *returnSize) {
    if (nums == NULL || numsSize < 0 || returnSize == NULL) return NULL;

    const int capacity = factorial(numsSize);
    int **permutations = (int **) malloc(capacity * sizeof(int *));
    *returnSize = 0;
    int *path = (int *) malloc(capacity * sizeof(int));
    int path_size = 0;
    bool *visited = (bool *) calloc(numsSize, sizeof(bool));

    permute_dfs(nums, numsSize, permutations, returnSize, path, &path_size, visited);

    free(visited);
    free(path);
    return permutations;
}
