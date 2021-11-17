#pragma once

#include "expression.h"

class IndexingExpression : public Expression
{
    IndexingExpression(Expression &obj, Expression &index);

    Literal &evaluate(Scope &evalScope) override;
};
