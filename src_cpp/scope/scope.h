#pragma once
#include <string>
#include <unordered_map>
#include "../expressions/literals/literal.h"
#include <memory>

class Scope
{
private:
    std::unordered_map<std::string, std::shared_ptr<Literal>> *contents;

public:
    Scope();
    ~Scope();

    std::shared_ptr<Literal>get(std::string identifier);

    void set(std::string identifier, std::shared_ptr<Literal> literal);
};