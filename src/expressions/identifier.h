#pragma once
#include <string>
#include "expression.h"

class Identifier : public Expression
{
    std::string name;

    Literal &evaluate(Scope &evalScope) override;
};
