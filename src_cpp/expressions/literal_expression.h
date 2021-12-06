#include "expression.h"
#include <memory>

class LiteralExpression : public Expression
{
    std::shared_ptr<Literal> value;

public:
    LiteralExpression(std::shared_ptr<Literal> val);

    std::shared_ptr<Literal> Evaluate(Scope &evalScope) override;
};