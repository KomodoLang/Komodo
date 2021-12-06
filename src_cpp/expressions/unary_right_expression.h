#pragma once
#include "../operators/unary/unary_right_operator.h"
#include "expression.h"

class UnaryRightExpression : public Expression
{
    UnaryRightExpression(Expression &operand, UnaryRightOperator op);

    std::shared_ptr<Literal>Evaluate(Scope &evalScope) override;
};
