#ifndef STRLIB
#define STRLIB

#include <stdio.h>

/**
 * 
*/
char *str_copy(char dest[], const char src[]);

/**
 * 
*/
size_t str_len(const char str[]);

/**
 * 
*/
char *str_rev(char str[]);

/**
 * 
*/
const char *str_chr(const char str[], const char ch);

/**
 * 
*/
int str_cmp(const char l[], const char r[]);

/**
 * 
*/
char *str_n_cpy(char dest[], const char src[], const size_t count);

/**
 * 
*/
char *str_cat(char dest[], const char src[]);

/**
 * 
*/
char *str_n_cat(char dest[], const char src[], const size_t count);

/**
 * 
*/
int put_str(const char str[]);

/**
 * 
*/
char *f_get_str(char str[], size_t count, FILE *file);

#endif // STRLIB