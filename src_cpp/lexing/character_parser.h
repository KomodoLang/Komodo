#pragma once
class CharacterParser
{
public:
    static bool is_number(char &c);

    static bool is_letter(char &c);
    
    static bool is_underscore(char &c);

    static bool is_whitespace(char &c);

    static bool is_symbol(char &c);
};