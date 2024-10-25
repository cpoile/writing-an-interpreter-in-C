#include <string.h>
#include <stdio.h>
#include "lexer/lexer_test.c"

int main(int argv, char **args) {
    if (argv > 1 && strcmp(args[1], "test") == 0) {
        TestNextToken();
    }

    printf("Hello, World! %d\n", 10001);
    return 0;
}
