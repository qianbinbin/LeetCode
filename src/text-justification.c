#include <text-justification.h>
#include <stdlib.h>
#include <string.h>

char **fullJustify_68(char **words, int wordsSize, int maxWidth, int *returnSize) {
    if (words == NULL || wordsSize < 1 || maxWidth < 1 || returnSize == NULL) return NULL;

    char **ret = (char **) malloc(wordsSize * sizeof(char *));
    *returnSize = 0;

    int start = 0, end;
    while (start < wordsSize) {
        char *str = (char *) malloc(maxWidth + 1);
        str[maxWidth] = '\0';
        int size = strlen(words[start]);
        memcpy(str, words[start], size);

        int length = size;
        for (end = start; end + 1 < wordsSize && length + end - start + 1 + strlen(words[end + 1]) <= maxWidth;
             ++end) {
            length += strlen(words[end + 1]);
        }

        if (end > start && end < wordsSize - 1) {
            int spaces = maxWidth - length;
            int each = spaces / (end - start);
            int extra = spaces % (end - start);

            for (int i = start + 1; i <= end; ++i) {
                memset(str + size, ' ', each);
                size += each;
                if (extra-- > 0) str[size++] = ' ';
                int l = strlen(words[i]);
                memcpy(str + size, words[i], l);
                size += l;
            }
        } else {
            for (int i = start + 1; i <= end; ++i) {
                str[size++] = ' ';
                int l = strlen(words[i]);
                memcpy(str + size, words[i], l);
                size += l;
            }
            if (size < maxWidth)
                memset(str + size, ' ', maxWidth - size);
        }

        ret[(*returnSize)++] = str;
        start = end + 1;
    }
    return ret;
}
