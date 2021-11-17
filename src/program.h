#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "lexing/token.h"
#include "expressions/identifier.h"

typedef int StatusCode;

class Program
{
public:
    std::vector<Token> token_list;
    std::string entry_point;

    // TODO fix this shitty temp solution
    std::vector<std::string> entry_point_lines;

    Program(std::string file_path);

    StatusCode simulate();

    void importFile(std::string file_name);

    void importIdentifiersFromFile(std::vector<std::string> idenitifiers, std::string file_name);
    std::vector<Token> lex_file(std::string file_path);
};
