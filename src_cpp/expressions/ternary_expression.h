#pragma once
#include "expression.h"

class TernaryExpression : public Expression
{
    TernaryExpression(Expression &condition, Expression &truthy, Expression &falsy);

    std::shared_ptr<Literal>Evaluate(Scope &evalScope) override;
};