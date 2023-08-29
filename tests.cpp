#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strlib.h"
#include "tests.h"

#define SIGN(x) (((x) > 0) - ((x) < 0))

/**
 * Finds the length of 2d array ended with NULL
*/
static size_t lenarr(const char *s[]);

/**
 * Finds the longest string in given array
*/
static size_t maxlenstr(const char *s[]);

int test_str_copy() {
    const char *src[] = {"aboba", "i", "", NULL};
    size_t max_len = maxlenstr(src);
    char **dest = (char**)calloc(lenarr(src), max_len);
    
    for (size_t i = 0; src[i] && dest[i]; i++) {
        if (strcmp(strcpy(dest[i], src[i]), str_copy(dest[i], src[i]))) {
            printf("test_str_copy failed\n");
            return -1;
        }
    }
    free(dest);
    return 0;
}

int test_str_cat() {
    char dest[][100]  = {"aboba", "gh", ""};
    const char *src[] = {"u", "i", NULL};

    for (size_t i = 0; src[i] && dest[i][0]; i++) {
        if (strcmp(strcat(dest[i], src[i]), str_cat(dest[i], src[i]))) {
            printf("test_str_cat failed\n");
            return -1;
        }
    }
    return 0;
}

int test_str_len() {
    const char *str[] = {"aboba", "1", NULL};

    for (size_t i = 0; str[i]; i++) {
        if (str_len(str[i]) != strlen(str[i])) {
            printf("test_str_len failed\n");
            return -1;
        }
    }
    return 0;
}

int test_str_chr() {
    const char *str[] = {"aboba", "abjhiwhfiwhqiofhuqhf", "9", NULL};
    const char ch[] = {'o', '0', '9'};

    for (size_t i = 0; str[i]; i++) {
        if (str_chr(str[i], ch[i]) != strchr(str[i], ch[i])) {
            printf("test_str_chr failed\n");
            return -1;
        }
    }
    return 0;
}

int test_str_cmp() {
    const char *l[] = {"aboba", "jGDUGUDuG", "\n", NULL};
    const char *r[] = {"aboba", "a", "z", NULL};

    for (size_t i = 0; l[i] && r[i]; i++) {
        if (SIGN(str_cmp(l[i], r[i])) != SIGN(strcmp(l[i], r[i]))) {
            printf("test_str_cmp failed\n");
            return -1;
        }
    }
    return 0;
}

static size_t lenarr(const char *s[]) {
    size_t i = 0;
    for (i = 0; s[i]; i++) {
        ;
    }
    return i;
}

static size_t maxlenstr(const char *s[]) {
    size_t max = 0;
    
    for (size_t i = 0; s[i]; i++) {
        size_t len = strlen(s[i]);
        if (len > max) {
            max = len;
        }
    }
    return max;
} 
