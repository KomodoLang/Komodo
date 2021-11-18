#include "../binary_operator.h"
#include <memory>

class AdditionOperator : public BinaryOperator
{
public:
    std::shared_ptr<Literal> Resolve(Scope &evalScope, Expression &operand1, Expression &operand2) override;
};