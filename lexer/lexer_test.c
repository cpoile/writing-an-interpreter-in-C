#pragma once
#include "lexer.c"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

void assert_eq(Token expected, Token actual, u64 curPosition)
{
    if (!token_equal(expected, actual))
    {
        fprintf(stderr, "\nExpected %s %s ; Received %s %s ; curPosition: %lld\n\n", TOKEN_TO_STR[expected.type],
                expected.literal, TOKEN_TO_STR[actual.type], actual.literal, curPosition);
        assert(false);
    }
}

void TestNextToken(void)
{
    char *input = "let five = 5;\n"
                  "let ten = 10;\n"
                  "\n"
                  "let add = fn(x, y) {\n"
                  "  x + y;\n"
                  "};\n"
                  "\n"
                  "let result = add(five, ten);\n";

    Token expected_tokens[] = {
        {LET, "let"},   {IDENT, "five"},  {ASSIGN, "="}, {INT, "5"},        {SEMICOLON, ";"}, {LET, "let"},
        {IDENT, "ten"}, {ASSIGN, "="},    {INT, "10"},   {SEMICOLON, ";"},  {LET, "let"},     {IDENT, "add"},
        {ASSIGN, "="},  {FUNCTION, "fn"}, {LPAREN, "("}, {IDENT, "x"},      {COMMA, ","},     {IDENT, "y"},
        {RPAREN, ")"},  {LBRACE, "{"},    {IDENT, "x"},  {PLUS, "+"},       {IDENT, "y"},     {SEMICOLON, ";"},
        {RBRACE, "}"},  {SEMICOLON, ";"}, {LET, "let"},  {IDENT, "result"}, {ASSIGN, "="},    {IDENT, "add"},
        {LPAREN, "("},  {IDENT, "five"},  {COMMA, ","},  {IDENT, "ten"},    {RPAREN, ")"},    {SEMICOLON, ";"},
        {E_O_F, ""},
    };

    Lexer l = NewLexer(input);

    int lenTokens = sizeof(expected_tokens) / sizeof(Token);

    for (int i = 0; i < lenTokens; i++)
    {
        Token next = NextToken(&l);

        assert_eq(expected_tokens[i], next, l.position);
    }
}
