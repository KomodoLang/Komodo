#include "identifier.h"

std::shared_ptr<Literal>Identifier::Evaluate(Scope &evalScope) 
{
    return evalScope.get(name);
}