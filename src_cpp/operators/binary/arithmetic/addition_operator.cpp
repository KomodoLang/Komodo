#include "addition_operator.h"
#include "../../../expressions/literals/literal.h"
#include "../../../expressions/literals/int_literal.h"
#include "../../../expressions/literals/double_literal.h"
#include "../../../exceptions/incompatible_type_exception.h"
#include <memory>

std::shared_ptr<Literal> AdditionOperator::Resolve(Scope &evalScope, Expression &op1, Expression &op2)
{
    operand1 = op1.Evaluate(evalScope);
    operand2 = op2.Evaluate(evalScope);

    if (ops_equal(LiteralType::INTEGER_LITERAL))
    {
        IntegerLiteral int1 = *dynamic_cast<IntegerLiteral *>(operand1.get());
        IntegerLiteral int2 = *dynamic_cast<IntegerLiteral *>(operand2.get());

        return std::make_shared<IntegerLiteral>(int1.getValue() + int2.getValue());
    }
    else if (ops_equal_asym(INTEGER_LITERAL, DOUBLE_LITERAL))
    {
        IntegerLiteral int1 = *dynamic_cast<IntegerLiteral *>(operand1.get());
        DoubleLiteral doub1 = *dynamic_cast<DoubleLiteral *>(operand2.get());

        return std::make_shared<DoubleLiteral>(int1.getValue() + doub1.getValue());
    }
    else if (ops_equal_asym(DOUBLE_LITERAL, INTEGER_LITERAL))
    {
        DoubleLiteral doub1 = *dynamic_cast<DoubleLiteral *>(operand1.get());
        IntegerLiteral int1 = *dynamic_cast<IntegerLiteral *>(operand2.get());

        return std::make_shared<DoubleLiteral>(int1.getValue() + doub1.getValue());
    }
    else if (ops_equal(LiteralType::DOUBLE_LITERAL))
    {
        DoubleLiteral doub1 = *dynamic_cast<DoubleLiteral *>(operand1.get());
        DoubleLiteral doub2 = *dynamic_cast<DoubleLiteral *>(operand2.get());

        return std::make_shared<DoubleLiteral>(doub2.getValue() + doub1.getValue());
    }
    else
    {
        throw incompatible_type_exception("addition", operand1->getType(), operand2.get()->getType());
    }
}