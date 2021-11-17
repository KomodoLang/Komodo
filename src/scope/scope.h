#include <string>
#include <unordered_map>

class Scope
{
private:
    std::unordered_map<std::string, Literal> *contents;

public:
    Scope();
    ~Scope();

    Literal &get(std::string identifier);

    void set(std::string identifier, Literal& literal);
};