#pragma once
#include "base.c"
#include "lexer.c"
#include "token.c"
#include <stdio.h>

const char *PROMPT = ">> ";

void
repl_start(FILE *in, FILE *out)
{
    char line[100];

    while (true)
    {
        fprintf(out, "%s", PROMPT);

        if (fgets(line, 100, in) == NULL)
        {
            printf("Goodbye!");
            return;
        }

        Lexer l = NewLexer(line);
        for (Token tok = NextToken(&l); tok.type != E_O_F; tok = NextToken(&l))
        {
            fprintf(out, "Token: %s, Literal: %s\n", TOKEN_TO_STR[tok.type], tok.literal);
        }
    }
}
