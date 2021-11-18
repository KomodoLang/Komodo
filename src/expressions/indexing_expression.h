#pragma once

#include "expression.h"

class IndexingExpression : public Expression
{
    IndexingExpression(Expression &obj, Expression &index);

    std::shared_ptr<Literal>Evaluate(Scope &evalScope) override;
};
