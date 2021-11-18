#include "bool_literal.h"

BoolLiteral::BoolLiteral(bool val) : value(val) {}

LiteralType BoolLiteral::getType() 
{
    return LiteralType::BOOLEAN_LITERAL;
}

bool BoolLiteral::getValue()
{
    return value;
}
