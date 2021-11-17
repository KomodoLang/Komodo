#pragma once

#include <vector>
#include "expression.h"

class FunctionCall : public Expression
{
    FunctionCall(Expression &functioName, std::vector<Expression> args);

    Literal &evaluate(Scope &evalScope) override;
};