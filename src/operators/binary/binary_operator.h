#include "./operator.h"
#include "../../expressions/literals/literal.h"

class BinaryOperator : public Operator
{
    virtual Literal &evaluate(Scope &evalScope, Expression &operand1, Expression &operand2) = 0;
};
