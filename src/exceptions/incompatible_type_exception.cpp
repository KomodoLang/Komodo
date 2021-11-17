#include "incompatible_type_exception.h"

incompatible_type_exception::incompatible_type_exception(std::string op, LiteralType t1, LiteralType t2) : operation(op), type1(t1), type2(t2) {}

const char *incompatible_type_exception::message() const throw() {
    return std::string("Incomaptible types " + std::to_string(type1) + " and " + std::to_string(type2) + "for operation " + operation ).c_str();
}