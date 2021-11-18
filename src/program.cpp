#include "program.h"
#include <fstream>
#include "lexing/character_parser.h"
#include "lexing/character_type.h"
#include "operators/binary/arithmetic/addition_operator.h"
#include "expressions/binary_expression.h"
#include "expressions/literals/int_literal.h"
#include "expressions/literals/double_literal.h"
#include "expressions/literal_expression.h"

Program::Program(std::string file_path)
{
    token_list = lex_file(file_path);
}

StatusCode Program::simulate()
{
    Scope evaluationScope;

    LiteralExpression operand1(std::make_shared<IntegerLiteral>(4));
    LiteralExpression operand2(std::make_shared<DoubleLiteral>(5));

    AdditionOperator op;

    std::cout << "Before Compare" << std::endl;

    std::shared_ptr<Literal> sum = BinaryExpression(operand1, op, operand2).Evaluate(evaluationScope);

    std::cout << "After Compare" << std::endl;

    std::cout << sum->getType() << std::endl;

    std::cout << "After Type" << std::endl;
    exit(0);

    // Parse
    bool hasPassedIncludes = false;
    std::vector<Identifier> globalScope;

    int ip = 0;
    while (ip < token_list.size())
    {
        Token &token = token_list.at(ip);

        int amountToMoveIp = 0;

        if (token.type != TokenType::IMPORT)
        {
            hasPassedIncludes = true;
        }

        switch (token.type)
        {
        // If we come across an include, evalutate it and parse the file for all the necessary variables
        case TokenType::IMPORT:
        {
            if (hasPassedIncludes)
            {
                std::cout << token << std::endl;
                token.printTokenError("Unexpected import after begining of file body. Imports can only be located at the top of a file. At", entry_point_lines);
                return 1;
            }

            int MAX_IMPORT_LENGTH = 10;
            bool reachedEndOfLineOrStatement = false;
            std::string importIdentifier;
            int tokenPointer = 0;
            bool isComplete = false;
            std::vector<std::string> idenitifiersToInclude;
            bool hasReachedFrom = false;
            std::string fileToIncldueFrom = "";

            while (!reachedEndOfLineOrStatement)
            {
                // If reached end of file before completed,
                if (tokenPointer + ip + 1 > token_list.size())
                {
                    token.printTokenError("Expected more arguments for 'import' intrinsic but found", entry_point_lines);
                    return 1;
                }

                Token &t = token_list.at(ip + tokenPointer);

                if (idenitifiersToInclude.size() >= MAX_IMPORT_LENGTH)
                {
                    token_list.at(ip + tokenPointer - 1).printTokenError("Import identifiers met or exceeded hard coded limit. Consider importing everything. At", entry_point_lines);
                    return 1;
                }

                if (t.type == TokenType::NEW_LINE || t.type == TokenType::SEMICOLON)
                {
                    reachedEndOfLineOrStatement = true;

                    if (!isComplete)
                    {
                        Token &previousToken = token_list.at(ip + tokenPointer - 1);
                        if (idenitifiersToInclude.size() > 1 && !hasReachedFrom)
                        {
                            t.printTokenError("Expected 'from' keyword since more than 2 identifiers are imported. At", entry_point_lines);
                        }
                        else if (tokenPointer == 1)
                        {
                            t.printTokenError("Expected identifier in import, but found", entry_point_lines);
                        }
                        else if (previousToken.type != TokenType::IDENTIFIER)
                        {
                            previousToken.printTokenError("Expected identifier in import, but found", entry_point_lines);
                        }
                        else
                        {
                            t.printTokenError("Invalid use of import statement", entry_point_lines);
                        }
                        return 1;
                    }
                    tokenPointer++;
                    continue;
                }

                if (!hasReachedFrom)
                {
                    // Parse include token
                    if (t.type == TokenType::IDENTIFIER)
                    {
                        Token &previousToken = token_list.at(ip + tokenPointer - 1);
                        if (previousToken.type == TokenType::IDENTIFIER)
                        {
                            t.printTokenError("Import identifiers not separated by comma. At", entry_point_lines);
                            return 1;
                        }

                        idenitifiersToInclude.push_back(t.value);
                        isComplete = idenitifiersToInclude.size() == 1;
                    }
                    else if (t.type == TokenType::COMMA)
                    {
                        if (idenitifiersToInclude.size() <= 0)
                        {
                            t.printTokenError("Expected identifier for 'import' intrinsic but found", entry_point_lines);
                            return 1;
                        }
                        isComplete = false;
                    }
                    else if (t.type == TokenType::FROM)
                    {
                        if (idenitifiersToInclude.size() <= 0)
                        {
                            t.printTokenError("Expected identifier for 'import' intrinsic but found", entry_point_lines);
                            return 1;
                        }
                        hasReachedFrom = true;
                        isComplete = false;
                    }
                }
                else
                {
                    if (t.type == TokenType::IDENTIFIER)
                    {
                        if (fileToIncldueFrom.length() > 0)
                        {
                            t.printTokenError("Duplicate file to include from", entry_point_lines);
                            return 1;
                        }
                        fileToIncldueFrom = t.value;
                        isComplete = true;
                    }
                    else
                    {
                        t.printTokenError("Expected identifier for 'from' intrinsic but found", entry_point_lines);
                        return 1;
                    }
                }

                tokenPointer++;
            }

            if (idenitifiersToInclude.size() == 1)
            {
                importFile(idenitifiersToInclude.at(0));
            }
            else
            {
                importIdentifiersFromFile(idenitifiersToInclude, fileToIncldueFrom);
            }

            amountToMoveIp += tokenPointer;

            break;
        }
        case TokenType::FUNCTION_DECLARATION:
        {
            // First find founction header
        }
        default:
            amountToMoveIp = 1;
            break;
        }

        // std::cout << token << std::endl;
        ip += amountToMoveIp;
    }
    return 0;
}

void Program::importFile(std::string file_name)
{
    std::cout << "Importing everything from: " << file_name << std::endl;
}

void Program::importIdentifiersFromFile(std::vector<std::string> idenitifiers, std::string file_name)
{
    std::cout << "From " << file_name << " importing: " << std::endl;
    for (auto &id : idenitifiers)
        std::cout << " - " << id << std::endl;
}

std::vector<Token> Program::lex_file(std::string file_path)
{
    std::ifstream file_stream(file_path);
    if (!file_stream.is_open())
    {
        std::cout << "ERROR: Unable to find file " << file_path << std::endl;
        exit(1);
    }

    std::string file_contents;
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file_stream, line))
    {
        // Filter out comments
        int index = line.find("//");
        if (index > 0)
        {
            line = line.substr(0, index);
        }
        lines.push_back(line);

        file_contents.append(line + '\n');
    }
    file_stream.close();

    CharacterType lastCharacterType = CharacterType::WHITE_SPACE;

    std::string current_token;
    std::vector<Token> tokens;
    int line_count = 1;
    int col_count = 0;

    char lastChar = ' ';
    for (int i = 0; i < file_contents.length(); i++)
    {
        char &c = file_contents.at(i);

        // writeString(std::cout, std::string(1, lastChar));
        // std::cout << std::endl;
        if (lastChar == '\n')
        {
            line_count++;
            col_count = 1;
        }
        else
        {
            col_count++;
        }

        // Is Number
        if (CharacterParser::is_number(c))
        {
            switch (lastCharacterType)
            {
            case CharacterType::NUMBER:
                // Middle of int
                current_token.push_back(c);
                break;
            // Last char was a space, start parsing the int
            case CharacterType::WHITE_SPACE:
                current_token.push_back(c);
                break;
            // If int is after a word with no space, it is counted as part of the identifier (i.e. varname1)
            case CharacterType::WORD:
                current_token.push_back(c);
                lastCharacterType = CharacterType::WORD;
                break;
            // Previous char was not a number push the last token and start pasring the int
            default:
                // Push Last Token into
                tokens.push_back(Token(lastCharacterType, current_token, file_path, line_count, col_count - current_token.length()));

                // Begin collection of next token
                current_token = c;
            }

            lastCharacterType = CharacterType::NUMBER;
        }
        // Is Letter
        else if (CharacterParser::is_letter(c) || CharacterParser::is_underscore(c))
        {
            switch (lastCharacterType)
            {
            case CharacterType::WORD:
                // Middle of word
                current_token.push_back(c);
                break;
            // Last char was a space, start parsing the int
            case CharacterType::WHITE_SPACE:
                current_token.push_back(c);
                break;
            // Previous char was not a word_char push the last token and start pasring the word
            default:
                // Push Last Token into
                tokens.push_back(Token(lastCharacterType, current_token, file_path, line_count, col_count - current_token.length()));

                // Begin collection of next token
                current_token = c;
            }

            lastCharacterType = CharacterType::WORD;
        }
        // Is Symbol
        else if (CharacterParser::is_symbol(c))
        {
            // Symbol only lasts 1 character, if it is ever detected, it should push the last valid token and push itself

            switch (lastCharacterType)
            {

            // Last char was a space, dont push it
            case CharacterType::WHITE_SPACE:
                break;
            default:
                // Push Last Token into vector
                tokens.push_back(Token(lastCharacterType, current_token, file_path, line_count, col_count - current_token.length()));
            }

            // Begin collection of next token
            current_token = c;

            lastCharacterType = CharacterType::SYMBOL;
        }
        // Is Whitespace
        else if (CharacterParser::is_whitespace(c))
        {
            switch (lastCharacterType)
            {
            // Ingore whitespace
            case CharacterType::WHITE_SPACE:
                break;
            // Previous char was comething other than whitespace so finish pushing that
            default:
                // Push Last Token into
                tokens.push_back(Token(lastCharacterType, current_token, file_path, line_count, col_count - current_token.length()));

                current_token = "";
            }

            lastCharacterType = CharacterType::WHITE_SPACE;
        }
        // Is Other (Control Characters)
        else
        {
        }

        lastChar = c;
    }
    entry_point_lines = lines;
    return tokens;
}
