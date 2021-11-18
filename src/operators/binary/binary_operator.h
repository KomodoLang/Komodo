#pragma once
#include "../operator.h"
#include "../../expressions/literals/literal.h"
#include "../../expressions/expression.h"
#include "../../scope/scope.h"
#include <memory>

class BinaryOperator : public Operator
{
public:
    std::shared_ptr<Literal> operand1;
    std::shared_ptr<Literal> operand2;

    virtual std::shared_ptr<Literal> Resolve(Scope &evalScope, Expression &operand1, Expression &operand2) = 0;

    /**
     * @brief true if both operands are equal to type 
     * 
     * @param type 
     */
    bool ops_equal(LiteralType type);

    bool ops_equal_asym(LiteralType type, LiteralType type2);
};
