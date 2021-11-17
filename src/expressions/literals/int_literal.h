#pragma once
#include "./literal.h"

class IntegerLiteral : public  Literal
{
    int value;

public:
    IntegerLiteral(int val);

    LiteralType getType() override;

    int getValue();
};