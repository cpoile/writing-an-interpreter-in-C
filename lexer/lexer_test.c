void assert_eq(Token expected, Token actual) {
    if (!token_equal(expected, actual)) {
        fprintf(stderr, "\nExpected %s %s ; Received %s %s\n\n", TOKEN_TO_STR[expected.type], expected.literal,
               TOKEN_TO_STR[actual.type], actual.literal);
        assert(false);
    }
}

void TestNextToken() {
    char *input = "=+(){},;";

    Token expected_tokens[] = {
            {ASSIGN,    "="},
            {PLUS,      "+"},
            {LPAREN,    "("},
            {RPAREN,    ")"},
            {LBRACE,    "{"},
            {RBRACE,    "}"},
            {COMMA,     ","},
            {SEMICOLON, ";"},
            {E_O_F,     ""},
    };

    Lexer l = NewLexer(input);

    int lenTokens = sizeof(expected_tokens) / sizeof(Token);

    for (int i = 0; i < lenTokens; i++) {
        Token next = NextToken(&l);

        assert_eq(expected_tokens[i], next);
    }
}
