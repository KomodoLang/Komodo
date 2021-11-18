#pragma once
#include "expression.h"
#include "../operators/binary/binary_operator.h"
#include <memory>

class BinaryExpression : public Expression
{
    Expression& operand1;
    BinaryOperator& op;
    Expression& operand2;

    public:
    BinaryExpression(Expression &operand1, BinaryOperator &op, Expression &operand2);

    std::shared_ptr<Literal> Evaluate(Scope &evalScope) override;
};
