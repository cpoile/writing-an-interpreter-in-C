#pragma once

#include "base.c"
#include "token.c"
#include <malloc.h>
#include <string.h>

typedef struct Lexer {
    char *input;
    size_t len; // the length of the original input. Stored because we tokenize
                // it by setting spaces to 0.
    u64 position;     // points to current character
    u64 readPosition; // points to the position after current character
    char ch;          // current char under examination
} Lexer;

void readChar(Lexer *l) {
    if (l->readPosition >= l->len) {
        l->ch = 0;
    } else {
        l->ch = l->input[l->readPosition];
    }
    l->position = l->readPosition;
    l->readPosition++;
}

Lexer NewLexer(char *input) {
    Lexer l = {.input = input,
               .len = strlen(input),
               .position = 0,
               .readPosition = 0,
               .ch = 0};
    readChar(&l);
    return l;
}

bool isLetter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

bool isInt(char ch) { return '0' <= ch && ch <= '9'; }

char *readIdentifier(Lexer *l) {
    char *start = l->input + l->position;
    u64 startPos = l->position;
    while (isLetter(l->ch)) {
        readChar(l);
    }
    u64 sz = l->position - startPos;
    char *duped = malloc(sz + 1);
    strncpy_s(duped, sz + 1, start, sz);
    duped[sz] = '\0';

    return duped;
}

static char *readInt(Lexer *l) {
    char *start = l->input + l->position;
    u64 startPos = l->position;
    // TODO: need to clean up this memory alloc.
    while (isInt(l->ch)) {
        readChar(l);
    }
    u64 sz = l->position - startPos;
    char *duped = malloc(sz + 1);
    strncpy_s(duped, sz + 1, start, sz);

    return duped;
}

static int getType(char *literal) {
    if (strcmp("let", literal) == 0) {
        return LET;
    } else if (strcmp("fn", literal) == 0) {
        return FUNCTION;
    } else {
        return IDENT;
    }
}

void skipWhitespace(Lexer *l) {
    while (l->ch == ' ' || l->ch == '\t' || l->ch == '\n' || l->ch == '\r') {
        readChar(l);
    }
}

Token NextToken(Lexer *l) {
    skipWhitespace(l);

    Token tok = (Token){ILLEGAL, ""};

    switch (l->ch) {
    case '=':
        tok = (Token){ASSIGN, "="};
        break;
    case ';':
        tok = (Token){SEMICOLON, ";"};
        break;
    case '(':
        tok = (Token){LPAREN, "("};
        break;
    case ')':
        tok = (Token){RPAREN, ")"};
        break;
    case ',':
        tok = (Token){COMMA, ","};
        break;
    case '+':
        tok = (Token){PLUS, "+"};
        break;
    case '{':
        tok = (Token){LBRACE, "{"};
        break;
    case '}':
        tok = (Token){RBRACE, "}"};
        break;
    case 0:
        tok = (Token){E_O_F, ""};
        break;
    case ' ':
        break;
    default:
        if (isLetter(l->ch)) {
            tok.literal = readIdentifier(l);
            tok.type = getType(tok.literal);
            return tok;
        } else if (isInt(l->ch)) {
            tok.literal = readInt(l);
            tok.type = INT;
            return tok;
        }
        // falls through with default illegal
        break;
    }

    readChar(l);
    return tok;
}
