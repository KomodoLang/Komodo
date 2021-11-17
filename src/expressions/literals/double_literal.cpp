#include "double_literal.h"
#include "literal.h"

DoubleLiteral::DoubleLiteral(double val) : value(val) {}

LiteralType DoubleLiteral::getType()
{
    return LiteralType::DOUBLE_LITERAL;
}

double DoubleLiteral::getValue()
{
    return value;
}
