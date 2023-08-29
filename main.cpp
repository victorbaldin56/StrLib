#include <stdio.h>
#include "strlib.h"
#include "tests.h"

int main() {
    test_str_copy();
    test_str_cat();
    test_str_chr();
    test_str_len();
    test_str_cmp();
    
    return 0;
}