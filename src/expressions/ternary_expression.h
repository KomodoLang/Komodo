#pragma once
#include "expression.h"

class TernaryExpression : public Expression
{
    TernaryExpression(Expression &condition, Expression &truthy, Expression &falsy);

    Literal &evaluate(Scope &evalScope) override;
};