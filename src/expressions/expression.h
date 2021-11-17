#pragma once

#include "literals/literal.h"
#include "../scope/scope.h"

class Expression
{
public:
    virtual Literal &evaluate(Scope &evalScope) = 0;
};