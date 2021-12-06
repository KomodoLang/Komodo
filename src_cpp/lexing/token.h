#pragma once
#include "token_type.h"
#include "character_type.h"

struct Token
{
    TokenType type;
    std::string value;
    std::string file;
    int line, col;

    Token(CharacterType &type, std::string &value, std::string &file, int line, int col);

    void printTokenError(std::string msg, std::vector<std::string> lines);

    friend std::ostream &operator<<(std::ostream &os, const Token &token);
};