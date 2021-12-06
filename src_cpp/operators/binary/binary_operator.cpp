#include "binary_operator.h"

bool BinaryOperator::ops_equal(LiteralType type) {
    LiteralType op1Type = operand1->getType();
    LiteralType op2Type = operand2->getType();

    return op1Type == op2Type && op1Type == type;
}

bool BinaryOperator::ops_equal_asym(LiteralType type1, LiteralType type2) {
    LiteralType op1Type = operand1->getType();
    LiteralType op2Type = operand2->getType();

    return op1Type == type1 && op2Type == type2;
}