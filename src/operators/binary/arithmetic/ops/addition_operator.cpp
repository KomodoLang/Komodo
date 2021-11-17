#include "arithmetic_operator.h"
#include "../../../expressions/literals/literal.h"

Literal &AdditionOperator::evaluate(Scope &evalScope, Expression &operand1, Expression &operand2) override
{
    Literal &op1 = operand1.evaluate(evalScope);
    Literal &op2 = operand2.evaluate(evalScope);

    LiteralType op1Type = op1.getType();
    LiteralType op2Type = op2.getType();

    if (op1Type == LiteralType::INTEGER_LITERAL && op2Type == LiteralType::INTEGER_LITERAL)
    {
        IntegerLiteral int1 = *dynamic_cast<IntegerLiteral *>(&op1);
        IntegerLiteral int2 = *dynamic_cast<IntegerLiteral *>(&op2);

        IntegerLiteral result(int1.getValue() + int2.getValue());
        return result;
    }
    else if (op1Type == LiteralType::INTEGER_LITERAL && op2Type == LiteralType::DOUBLE_LITERAL)
    {
        IntegerLiteral int1 = *dynamic_cast<IntegerLiteral *>(&op1);
        DoubleLiteral doub1 = *dynamic_cast<DoubleLiteral *>(&op2);

        DoubleLiteral result(int1.getValue() + doub1.getValue());
        return result;
    }
    else if (op1Type == LiteralType::DOUBLE_LITERAL && op2Type == LiteralType::INTEGER_LITERAL)
    {
        DoubleLiteral doub1 = *dynamic_cast<DoubleLiteral *>(&op1);
        IntegerLiteral int1 = *dynamic_cast<IntegerLiteral *>(&op2);

        DoubleLiteral result(int1.getValue() + doub1.getValue());
        return result;
    }
    else if (op1Type == LiteralType::DOUBLE_LITERAL && op2Type == LiteralType::DOUBLE_LITERAL)
    {
        DoubleLiteral doub1 = *dynamic_cast<DoubleLiteral *>(&op1);
        DoubleLiteral doub2 = *dynamic_cast<DoubleLiteral *>(&op2);

        DoubleLiteral result(doub2.getValue() + doub1.getValue());
        return result;
    }
    else
    {
        throw incompatible_type_exception("addition", op1, op2);
    }
}