#include "identifier.h"

Literal &Identifier::evaluate(Scope &evalScope) 
{
    return evalScope.get(name);
}