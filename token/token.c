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
    MINUS,
    BANG,
    ASTERISK,
    SLASH,
    LT,
    GT,
    EQ,
    NOT_EQ,

    // Delimiters
    COMMA,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    // Keywords
    FUNCTION,
    LET,
    TRUE,
    FALSE,
    IF,
    ELSE,
    RETURN,
};

const char *TOKEN_TO_STR[] = {"ILLEGAL", "EOF",       "IDENT",  "INT",    "ASSIGN", "PLUS",   "MINUS",
                              "BANG",    "ASTERISK",  "SLASH",  "LT",     "GT",     "EQ",     "NOT_EQ",
                              "COMMA",   "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "FUNCTION",
                              "LET",     "TRUE",      "FALSE",  "IF",     "ELSE",   "RETURN"};

typedef struct
{
    int   type;
    char *literal;
} Token;

bool token_equal(Token a, Token b)
{
    return (a.type == b.type && strcmp(a.literal, b.literal) == 0);
}
