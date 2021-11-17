#pragma once
#include "../../scope/scope.h"
#include "../../expressions/expression.h"
#include "../binary_operator.h"

class ArithmeticOperator : public BinaryOperator
{
    Literal &evaluate(Scope &evalScope, Expression &operand1, Expression &operand2) override;
};