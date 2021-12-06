#pragma once

#include <vector>
#include "expression.h"

class FunctionCall : public Expression
{
    FunctionCall(Expression &functioName, std::vector<Expression> args);

    std::shared_ptr<Literal> Evaluate(Scope &evalScope) override;
};