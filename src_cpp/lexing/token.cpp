#include "../util/ansi_codes.h"
#include "character_type.h"
#include <string>
#include <vector>
#include <iostream>
#include "token.h"

Token::Token(CharacterType &type,
             std::string &value,
             std::string &file,
             int line,
             int col)
{
    this->value = value;
    this->file = file;
    this->line = line;
    this->col = col;

    // Calculate Token Type
    switch (type)
    {
    case CharacterType::WORD:
        if (value == "int")
            this->type = TokenType::PRIMATIVE_TYPE_ANNOTATION;
        else if (value == "char")
            this->type = TokenType::PRIMATIVE_TYPE_ANNOTATION;
        else if (value == "double")
            this->type = TokenType::PRIMATIVE_TYPE_ANNOTATION;
        else if (value == "long")
            this->type = TokenType::PRIMATIVE_TYPE_ANNOTATION;
        else if (value == "string")
            this->type = TokenType::PRIMATIVE_TYPE_ANNOTATION;
        else if (value == "bool")
            this->type = TokenType::PRIMATIVE_TYPE_ANNOTATION;

        else if (value == "true")
            this->type = TokenType::BOOL;
        else if (value == "false")
            this->type = TokenType::BOOL;

        else if (value == "if")
            this->type = TokenType::CONTROL_FLOW;
        else if (value == "else")
            this->type = TokenType::CONTROL_FLOW;
        else if (value == "while")
            this->type = TokenType::CONTROL_FLOW;
        else if (value == "match")
            this->type = TokenType::CONTROL_FLOW;

        else if (value == "import")
            this->type = TokenType::IMPORT;
        else if (value == "from")
            this->type = TokenType::FROM;

        else if (value == "func")
            this->type = TokenType::FUNCTION_DECLARATION;
        else if (value == "let")
            this->type = TokenType::VARIABLE_DECLARATION;
        else if (value == "const")
            this->type = TokenType::ACCESS_MODIFIER;
        else if (value == "pub")
            this->type = TokenType::ACCESS_MODIFIER;
        else if (value == "priv")
            this->type = TokenType::ACCESS_MODIFIER;
        else if (value == "return")
            this->type = TokenType::RETURN;
        else
            this->type = TokenType::IDENTIFIER;
        break;

    // TODO Add Double And ALt Number System Parsing
    case CharacterType::NUMBER:
        this->type = TokenType::INT;
        break;

    case CharacterType::SYMBOL:
        if (value == ";")
            this->type = TokenType::SEMICOLON;
        else if (value == "(")
            this->type = TokenType::OPEN_PAREN;
        else if (value == ")")
            this->type = TokenType::CLOSE_PAREN;
        else if (value == "{")
            this->type = TokenType::OPEN_CURLY;
        else if (value == "}")
            this->type = TokenType::CLOSE_CURLY;
        else if (value == "[")
            this->type = TokenType::OPEN_BRACKET;
        else if (value == "]")
            this->type = TokenType::CLOSE_BRACKET;
        else if (value == "$")
            this->type = TokenType::DOLLAR_SIGN;
        else if (value == ".")
            this->type = TokenType::PERIOD;
        else if (value == ",")
            this->type = TokenType::COMMA;
        else if (value == ":")
            this->type = TokenType::COLON;
        else if (value == "?")
            this->type = TokenType::QUESTION_MARK;
        else if (value == "@")
            this->type = TokenType::AT_SYMBOL;
        else if (value == "=")
            this->type = TokenType::ASSIGN_OPERATOR;
        else if (value == "=>")
            this->type = TokenType::LAMBDA;

        // Math
        else if (value == "+")
            this->type = TokenType::PLUS_OPERATOR;
        else if (value == "-")
            this->type = TokenType::MINUS_OPERATOR;
        else if (value == "/")
            this->type = TokenType::DIV_OPERATOR;
        else if (value == "/~")
            this->type = TokenType::FLOAT_DIV_OPERATOR;
        else if (value == "%")
            this->type = TokenType::MOD_OPERATOR;

        // Bitwise
        else if (value == ">>")
            this->type = TokenType::SHIFT_RIGHT_OPERATOR;
        else if (value == "<<")
            this->type = TokenType::SHIFT_LEFT_OPERATOR;
        else if (value == "|")
            this->type = TokenType::BITWISE_OR_OPERATOR;
        else if (value == "&")
            this->type = TokenType::BITWISE_AND_OPERATOR;
        else if (value == "~")
            this->type = TokenType::BITWISE_INVERT_OPERATOR;
        else if (value == "^")
            this->type = TokenType::XOR_OPERATOR;

        // Conditionals
        else if (value == "||")
            this->type = TokenType::OR_OPERATOR;
        else if (value == "&&")
            this->type = TokenType::AND_OPERATOR;
        else if (value == "??")
            this->type = TokenType::NULLISH_COALESCING_OPERATOR;
        else if (value == "==")
            this->type = TokenType::EQUALS_OPERATOR;
        else if (value == "===")
            this->type = TokenType::STRICT_EQUALS_OPERATOR;
        else if (value == "!")
            this->type = TokenType::NOT_OPERATOR;
        else if (value == "<")
            this->type = TokenType::LT_OPERATOR;
        else if (value == ">")
            this->type = TokenType::GT_OPERATOR;
        else if (value == "<=")
            this->type = TokenType::LTE_OPERATOR;
        else if (value == ">=")
            this->type = TokenType::GTE_OPERATOR;

        // Shorthands
        else if (value == "+=")
            this->type = TokenType::PLUS_EQUALS_OPERATOR;
        else if (value == "-=")
            this->type = TokenType::MINUS_EQUALS_OPERATOR;
        else if (value == "/=")
            this->type = TokenType::DIV_EQUALS_OPERATOR;
        else if (value == "/~=")
            this->type = TokenType::FLOAT_DIV_EQUALS_OPERATOR;
        else if (value == "%=")
            this->type = TokenType::MOD_EQUALS_OPERATOR;

        else if (value == ">>=")
            this->type = TokenType::SHIFT_RIGHT_EQUALS_OPERATOR;
        else if (value == "<<=")
            this->type = TokenType::SHIFT_LEFT_EQUALS_OPERATOR;
        else if (value == "|=")
            this->type = TokenType::BITWISE_OR_EQUALS_OPERATOR;
        else if (value == "&=")
            this->type = TokenType::BITWISE_AND_EQUALS_OPERATOR;
        else if (value == "~=")
            this->type = TokenType::BITWISE_INVERT_EQUALS_OPERATOR;
        else if (value == "^=")
            this->type = TokenType::XOR_EQUALS_OPERATOR;
    }
}

void Token::printTokenError(std::string msg, std::vector<std::string> lines)
{
    // Prefix
    std::cerr << RED << "[ERROR] " << RESET;

    // File Path
    std::cerr << GREEN << "./" << this->file << RESET << ":" << CYAN << this->line << RESET << ":" << YELLOW << this->col << RESET;

    // Message and offending token
    std::cerr << " " << msg << MAGENTA << " '" << this->value << "'" << RESET << std::endl;

    // Calculate highlight message
    std::string line = lines.at(this->line - 1);
    auto str_start = line.substr(0, this->col - 1);
    // std::cout << "Start: " << str_start << std::endl;
    auto str_offender = line.substr(this->col - 1, this->value.length());
    // std::cout << "Middle: " << str_start << std::endl;
    auto str_end = line.substr(this->col - 1 + this->value.length());
    // std::cout << "End: " << str_start << std::endl;

    // Display of offending line
    std::cerr << CYAN << this->line << " | " << RESET << str_start << BRIGHT_RED_UNDERLINE << str_offender << RESET << str_end << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Token &token)
{
    // [Token]: TYPE: 0, Value: "23462", File: "foo.gec", Line: 1, Col: 4
    os << "[Token]: Type: " << token.type << ", Value: \"" << token.value << "\", File: \"" << token.file << ", Line: " << token.line << ", Col: " << token.col;
    return os;
}
