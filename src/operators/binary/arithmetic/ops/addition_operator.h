#include "../arithmetic_operator.h"

class AdditionOperator : public ArithmeticOperator
{
    Literal &evaluate(Scope &evalScope, Expression &operand1, Expression &operand2) override;
};