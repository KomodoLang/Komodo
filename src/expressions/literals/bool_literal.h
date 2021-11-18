#pragma once
#include "./literal.h"

class BoolLiteral : public  Literal
{
    bool value;

public:
    BoolLiteral(bool val);

    LiteralType getType() override;

    bool getValue();
};