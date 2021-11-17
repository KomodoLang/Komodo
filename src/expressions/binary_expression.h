#pragma once
#include "expression.h"
#include "../operators/binary/binary_operator.h"

class BinaryExpression : public Expression
{
    BinaryExpression(Expression &operand1, BinaryOperator &op, Expression &operand2);

    Literal &evaluate(Scope &evalScope) override;
};
