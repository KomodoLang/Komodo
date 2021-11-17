#include "identifier.h"

Literal &Identifier::evaluate(Scope &evalScope) override
{
    return evalScope.get(name);
}