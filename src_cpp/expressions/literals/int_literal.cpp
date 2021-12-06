#include "int_literal.h"

IntegerLiteral::IntegerLiteral(int val) : value(val) {}

LiteralType IntegerLiteral::getType() 
{
    return LiteralType::INTEGER_LITERAL;
}

int IntegerLiteral::getValue()
{
    return value;
}
