#pragma once
#include "literal.h"

class DoubleLiteral : public Literal
{
    double value;

public:
    DoubleLiteral(double val);

    LiteralType getType() override;

    double getValue();
};