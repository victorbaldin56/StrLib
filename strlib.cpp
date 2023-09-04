#include <assert.h>
#include <stdlib.h>
#include "strlib.h"

char *str_copy(char dest[], const char src[]) {
    assert(dest);
    assert(src);
    assert(dest != src);
    
    size_t i = 0;
    
    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }

    dest[i] = '\0';
    return dest;
}

size_t str_len(const char str[]) {
    assert(str);

    size_t i = 0;
    
    for (i = 0; str[i]; i++) {
        ;
    }
    
    return i;
}

const char *str_chr(const char str[], const char ch) {
    assert(str);

    size_t i = 0;
    
    for (i = 0; str[i]; i++) {
        if (str[i] == ch) {
            return str + i;
        }
    }
    
    if (!ch) {
        return str + i;
    }

    return NULL;
}

int str_cmp(const char l[], const char r[]) {
    assert(l);
    assert(r);
    
    size_t i = 0;
    
    do {
        if (l[i] > r[i]) {
            return 1;
        }
        else if (l[i] < r[i]) {
            return -1;
        }
        i++;
    } while (l[i] && r[i]);
    
    return 0;
}

char *str_n_cpy(char dest[], const char src[], const size_t count) {
    assert(dest);
    assert(src);
    assert(dest != src);
    assert(count);

    size_t i = 0;
    
    while (i < count && src[i]) {
        dest[i] = src[i];
        i++;
    }

    while (i < count) {
        dest[i] = '\0';
    }
    
    return dest;
}

char *str_cat(char dest[], const char src[]) {
    assert(dest);
    assert(src);
    
    size_t i = 0;
    
    for (i = 0; dest[i]; i++) {
        ;
    }

    size_t j = 0;
    
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return dest;
}

char *str_n_cat(char dest[], const char src[], const size_t count) {
    assert(dest);
    assert(src);
    assert(count);

    size_t i = 0;
    for (i = 0; dest[i]; i++) {
        ;
    }
    size_t j = 0;
    
    while (src[j] && j < count) {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return dest;
}

int put_str(const char str[]) {
    assert(str);
    
    size_t i = 0;
    
    for (i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
    }

    putchar('\n');
    return 0;
}

char *f_get_str(char str[], const size_t count, FILE *stream) {
    assert(str);
    assert(stream);
    assert(count);

    int c = fgetc(stream);
    size_t i = 0;

    while (c != EOF && i < count - 1) {
        str[i] = (char)c;
        c = fgetc(stream);
        if (c == '\n') {
            return str;
        }
        i++;
    }

    str[i] = '\0';
    return str;
}

ssize_t get_line(char **lineptr, size_t *n, FILE *stream) {
    assert(stream);
    assert(n);

    if (!lineptr) {
        lineptr = (char **)(calloc(*n, sizeof(char)));
        if (!lineptr) {
            return -1;
        }
    }

    size_t orig_size = sizeof(**lineptr);
    if (orig_size < *n) {
        size_t n_size = sizeof(realloc(lineptr, *n));
        if (n_size == orig_size) {
            return -1;
        }
    }

    *lineptr = f_get_str(*lineptr, *n, stream);
    return str_len(*lineptr);
}
