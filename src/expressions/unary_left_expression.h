#pragma once
#include "expression.h"
#include "../operators/unary/unary_left_operator.h"

class UnaryLeftExpression : public Expression
{
    UnaryLeftExpression(UnaryLeftOperator op, Expression &operand);

    Literal &evaluate(Scope &evalScope) override;
};