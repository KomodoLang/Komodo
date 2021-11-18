#include "binary_expression.h"

BinaryExpression::BinaryExpression(Expression &operand1, BinaryOperator &op, Expression &operand2) : operand1(operand1), op(op), operand2(operand2)
{
}

std::shared_ptr<Literal> BinaryExpression::Evaluate(Scope &evalScope)
{
    return op.Resolve(evalScope, operand1, operand2);
}
