#include "char_literal.h"

CharLiteral::CharLiteral(char val) : value(val) {}

LiteralType CharLiteral::getType() 
{
    return LiteralType::CHARACTER_LITERAL;
}

char CharLiteral::getValue()
{
    return value;
}
