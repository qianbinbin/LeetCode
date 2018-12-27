#include "substring_with_concatenation_of_all_words.h"

#include <stdlib.h>
#include <string.h>

static char *str(char *str) {
    const size_t len = strlen(str);
    char *ret = (char *) malloc(len + 1);
    strcpy(ret, str);
    return ret;
}

static char *substr(char *str, size_t start, size_t len) {
    char *ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    memcpy(ret, str + start, len);
    return ret;
}

#define HASH_MAP_SIZE 256

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hash_code(char *key) {
    int ret = 0;
    const size_t len = strlen(key);
    for (size_t i = 0; i < len; ++i)
        ret = ret * 31 + key[i];
    return ret;
}

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (map->entries + i)->next = NULL;
    return map;
}

static int hashmap_increase(hashmap *map, char *key) {
    size_t index = (size_t) (hash_code(key) & (HASH_MAP_SIZE - 1));
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            int ret = e->next->value;
            ++e->next->value;
            return ret;
        }
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = str(key);
    new->value = 1;
    new->next = NULL;
    e->next = new;
    return 0;
}

static int hashmap_get(hashmap *map, char *key) {
    size_t index = (size_t) (hash_code(key) & (HASH_MAP_SIZE - 1));
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return e->next->value;
        e = e->next;
    }
    return 0;
}

static void hashmap_free(hashmap *map) {
    entry *e, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        e = map->entries + i;
        while (e->next != NULL) {
            tmp = e->next;
            e->next = tmp->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(map);
}

int *findSubstring_30_1(char *s, char **words, int wordsSize, int *returnSize) {
    if (s == NULL || words == NULL || wordsSize < 1 || returnSize == NULL) return NULL;

    size_t capacity = 16;
    int *ret = (int *) malloc(capacity * sizeof(int));
    *returnSize = 0;

    hashmap *map = hashmap_create();
    for (int i = 0; i < wordsSize; ++i)
        hashmap_increase(map, words[i]);

    const int len = strlen(s), width = strlen(words[0]);
    const int sub_len = wordsSize * width;

    const int end = len - sub_len;
    for (int i = 0; i <= end; ++i) {
        int word_count = 0;
        hashmap *exist = hashmap_create();
        const int j_end = i + sub_len;
        for (int j = i; j < j_end; j += width) {
            char *tmp = substr(s, j, width);
            int max = hashmap_get(map, tmp);
            if (max == 0) {
                free(tmp);
                break;
            }
            int old = hashmap_increase(exist, tmp);
            if (old >= max) {
                free(tmp);
                break;
            }
            ++word_count;
            free(tmp);
        }
        hashmap_free(exist);
        if (word_count == wordsSize) {
            if (*returnSize >= capacity) {
                capacity *= 2;
                ret = (int *) realloc(ret, capacity * sizeof(int));
            }
            ret[(*returnSize)++] = i;
        }
    }

    hashmap_free(map);

    ret = (int *) realloc(ret, (*returnSize) * sizeof(int));
    return ret;
}
