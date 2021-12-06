#pragma once

#include "literals/literal.h"
#include "../scope/scope.h"
#include <memory>

class Expression
{
public:
    virtual std::shared_ptr<Literal> Evaluate(Scope &evalScope) = 0;
};