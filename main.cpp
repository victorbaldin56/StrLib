#include <stdio.h>
#include "strlib.h"
#include "tests.h"

int main() {
    if (!test_str_copy()  &&
        !test_str_cat()   &&
        !test_str_chr()   &&
        !test_str_len()   &&
        !test_str_cmp()   &&
        !test_f_get_str() &&
        !test_get_line()) {
            return 0;
        }
    return -1;
}