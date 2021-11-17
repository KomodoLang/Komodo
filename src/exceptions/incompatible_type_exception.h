#include <stdexcept>
#include <string>
#include "../expressions/literals/literal.h"

class incompatible_type_exception : public std::exception
{
    std::string operation;
    LiteralType type1;
    LiteralType type2;

public:
    incompatible_type_exception(std::string op, LiteralType t1, LiteralType t2);

    virtual const char *message() const throw();
};