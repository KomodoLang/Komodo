#include "literal_expression.h"

LiteralExpression::LiteralExpression(std::shared_ptr<Literal> val) {
    this->value = val;
}

std::shared_ptr<Literal> LiteralExpression::Evaluate(Scope &evalScope)
{
    return this->value;
}