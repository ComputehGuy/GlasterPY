#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "utf8proc.h"

#define NEWLINE 0
#define INDENT 1
#define IDENTIFIER 2
#define KEYWORD 3
#define LITERAL 4
#define OPERATOR 5
#define DELIMITER 6
#define BACKSLASH 7
#define TAB 8
#define COMMENT 9
#define SPACE 10

struct Token
{
    int TOKEN_TYPE; // (eg. INTEGER, STRING, SYMBOL, OPERATOR, OPENING_BRACE, CLOSING_BRACE, KEYWORD, SPECIAL_PUNCTUATION)
    char *TOKEN_VALUE;// (eg. 34,    "test", foo,    +,        [,             },             int,     ;                  )
};

class GlasterpyLexer {

    public:
        static std::vector<Token> lex(char *line, int len);

    private:
        static bool validate_identifier(char *line, int len);

};


