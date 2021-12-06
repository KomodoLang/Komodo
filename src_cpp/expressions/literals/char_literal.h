#pragma once
#include "./literal.h"

class CharLiteral : public  Literal
{
    char value;

public:
    CharLiteral(char val);

    LiteralType getType() override;

    char getValue();
};