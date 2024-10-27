#include "lexer/lexer_test.c"
#include "repl/repl.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argv, char **args)
{
    if (argv > 1 && strcmp(args[1], "test") == 0)
    {
        TestNextToken();
        printf("\nTests passed!\n");
    }

    char   *username;
    size_t  len;
    errno_t err = _dupenv_s(&username, &len, "USERNAME");
    if (err)
        return -1;

    printf("Hello %s! This is the Monkey programming language!\n", username);
    printf("Feel free to type in commands\n");

    repl_start(stdin, stdout);

    free(username);
    return 0;
}
