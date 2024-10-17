typedef struct Lexer {
    char *input;
    int position;     // points to current character
    int readPosition; // points to the position after current character
    char ch;         // current char under examination
} Lexer;

void readChar(Lexer *l) {
    if (l->readPosition >= strlen(l->input)) {
        l->ch = 0;
    } else {
        l->ch = l->input[l->readPosition];
    }
    l->position = l->readPosition;
    l->readPosition++;
}

Lexer NewLexer(char *input) {
    Lexer l = {.input = input, .position = 0, .readPosition = 0, .ch = 0};
    readChar(&l);
    return l;
}

Token NextToken(Lexer *l) {
    Token tok;

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
        default:
            assert(false);
    }

    readChar(l);
    return tok;
}
