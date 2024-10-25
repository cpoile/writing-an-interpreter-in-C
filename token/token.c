#pragma once
#include "base.c"
#include <string.h>

enum TOKEN
{
    ILLEGAL,
    E_O_F,

    // Identifiers and literals
    IDENT,
    INT,

    // Operators
    ASSIGN,
    PLUS,

    // Delimiters
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    // Keywords
    FUNCTION,
    LET
};

const char *TOKEN_TO_STR[] = {"ILLEGAL",   "EOF",    "IDENT",  "INT",    "ASSIGN", "PLUS",     "COMMA",
                              "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "FUNCTION", "LET"};

typedef struct
{
    int   type;
    char *literal;
} Token;

bool token_equal(Token a, Token b)
{
    return (a.type == b.type && strcmp(a.literal, b.literal) == 0);
}
