#pragma once
#include <string>
#include "expression.h"

class Identifier : public Expression
{
    std::string name;

    std::shared_ptr<Literal>Evaluate(Scope &evalScope) override;
};
