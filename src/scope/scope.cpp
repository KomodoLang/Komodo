#include <string>
#include <unordered_map>
#include "../expressions/literals/literal.h"

class Scope
{
private:
    std::unordered_map<std::string, Literal> *contents;

public:
    Scope()
    {
        contents = new std::unordered_map<std::string, Literal>();
    }

    ~Scope()
    {
        delete contents;
    }

    Literal &get(std::string identifier)
    {
        return contents->find(identifier)->second;
    };

    void set(std::string identifier, Literal& literal)
    {
        // if (!contents->contains(identifier))
        // {
        //     contents->insert({identifier, literal});
        // }
    };
};