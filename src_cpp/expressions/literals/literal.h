#pragma once

enum LiteralType
{
    INTEGER_LITERAL,
    DOUBLE_LITERAL,
    LONG_LITERAL,
    BOOLEAN_LITERAL,
    CHARACTER_LITERAL,
    STRING_LITERAL
};

class Literal
{
public:
    virtual LiteralType getType() = 0;
};