#include <string>
#include <unordered_map>
#include "../expressions/literals/literal.h"
#include "scope.h"

Scope::Scope()
{
    contents = new std::unordered_map<std::string, std::shared_ptr<Literal>>();
}

Scope::~Scope()
{
    delete contents;
}

std::shared_ptr<Literal>Scope::get(std::string identifier)
{
    return contents->find(identifier)->second;
};

void Scope::set(std::string identifier, std::shared_ptr<Literal>literal){
    // if (!contents->contains(identifier))
    // {
    //     contents->insert({identifier, literal});
    // }
};
