#include <string>
#include "character_parser.h"

bool CharacterParser::is_number(char &c)
{
    return c >= 48 && c <= 57;
}

bool CharacterParser::is_letter(char &c)
{
    return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}

bool CharacterParser::is_underscore(char &c)
{
    return c == 95;
}

bool CharacterParser::is_whitespace(char &c)
{
    return isspace(c);
}

bool CharacterParser::is_symbol(char &c)
{
    return c >= 33 && c <= 47 || c >= 58 && c <= 64 || c >= 92 && c <= 96 || c >= 123 && c <= 126;
}
