import {readFile} from 'fs/promises'

class Token {
    type: TokenType
    value: string
    file: string
    line: number
    col: number

    constructor(type: CharacterType, value: string,  file:string,  line: number,  col:number) {
        this.value = value;
    this.file = file;
    this.line = line;
    this.col = col;


    // Calculate Token Type
    switch (type)
    {
        case CharacterType.WORD:
            if (value == "int")
                this.type = TokenType.PRIMATIVE_TYPE_ANNOTATION;
            else if (value == "char")
                this.type = TokenType.PRIMATIVE_TYPE_ANNOTATION;
            else if (value == "double")
                this.type = TokenType.PRIMATIVE_TYPE_ANNOTATION;
            else if (value == "long")
                this.type = TokenType.PRIMATIVE_TYPE_ANNOTATION;
            else if (value == "string")
                this.type = TokenType.PRIMATIVE_TYPE_ANNOTATION;
            else if (value == "bool")
                this.type = TokenType.PRIMATIVE_TYPE_ANNOTATION;

            else if (value == "true")
                this.type = TokenType.BOOL;
            else if (value == "false")
                this.type = TokenType.BOOL;

            else if (value == "if")
                this.type = TokenType.CONTROL_FLOW;
            else if (value == "else")
                this.type = TokenType.CONTROL_FLOW;
            else if (value == "while")
                this.type = TokenType.CONTROL_FLOW;
            else if (value == "match")
                this.type = TokenType.CONTROL_FLOW;

            else if (value == "import")
                this.type = TokenType.IMPORT;
            else if (value == "from")
                this.type = TokenType.FROM;

            else if (value == "func")
                this.type = TokenType.FUNCTION_DECLARATION;
            else if (value == "let")
                this.type = TokenType.VARIABLE_DECLARATION;
            else if (value == "const")
                this.type = TokenType.ACCESS_MODIFIER;
            else if (value == "pub")
                this.type = TokenType.ACCESS_MODIFIER;
            else if (value == "priv")
                this.type = TokenType.ACCESS_MODIFIER;
            else if (value == "return")
                this.type = TokenType.RETURN;
            else
                this.type = TokenType.IDENTIFIER;
            break;

        // TODO Add Double And ALt Number System Parsing
        case CharacterType.NUMBER:
            this.type = TokenType.INT;
            break;

        case CharacterType.SYMBOL:
            if (value == ";")
                this.type = TokenType.SEMICOLON;
            else if (value == "(")
                this.type = TokenType.OPEN_PAREN;
            else if (value == ")")
                this.type = TokenType.CLOSE_PAREN;
            else if (value == "{")
                this.type = TokenType.OPEN_CURLY;
            else if (value == "}")
                this.type = TokenType.CLOSE_CURLY;
            else if (value == "[")
                this.type = TokenType.OPEN_BRACKET;
            else if (value == "]")
                this.type = TokenType.CLOSE_BRACKET;
            else if (value == "$")
                this.type = TokenType.DOLLAR_SIGN;
            else if (value == ".")
                this.type = TokenType.PERIOD;
            else if (value == ",")
                this.type = TokenType.COMMA;
            else if (value == ":")
                this.type = TokenType.COLON;
            else if (value == "?")
                this.type = TokenType.QUESTION_MARK;
            else if (value == "@")
                this.type = TokenType.AT_SYMBOL;
            else if (value == "=")
                this.type = TokenType.ASSIGN_OPERATOR;
            else if (value == "=>")
                this.type = TokenType.LAMBDA;

            // Math
            else if (value == "+")
                this.type = TokenType.PLUS_OPERATOR;
            else if (value == "-")
                this.type = TokenType.MINUS_OPERATOR;
            else if (value == "/")
                this.type = TokenType.DIV_OPERATOR;
            else if (value == "/~")
                this.type = TokenType.FLOAT_DIV_OPERATOR;
            else if (value == "%")
                this.type = TokenType.MOD_OPERATOR;

            // Bitwise
            else if (value == ">>")
                this.type = TokenType.SHIFT_RIGHT_OPERATOR;
            else if (value == "<<")
                this.type = TokenType.SHIFT_LEFT_OPERATOR;
            else if (value == "|")
                this.type = TokenType.BITWISE_OR_OPERATOR;
            else if (value == "&")
                this.type = TokenType.BITWISE_AND_OPERATOR;
            else if (value == "~")
                this.type = TokenType.BITWISE_INVERT_OPERATOR;
            else if (value == "^")
                this.type = TokenType.XOR_OPERATOR;

            // Conditionals
            else if (value == "||")
                this.type = TokenType.OR_OPERATOR;
            else if (value == "&&")
                this.type = TokenType.AND_OPERATOR;
            else if (value == "??")
                this.type = TokenType.NULLISH_COALESCING_OPERATOR;
            else if (value == "==")
                this.type = TokenType.EQUALS_OPERATOR;
            else if (value == "===")
                this.type = TokenType.STRICT_EQUALS_OPERATOR;
            else if (value == "!")
                this.type = TokenType.NOT_OPERATOR;
            else if (value == "<")
                this.type = TokenType.LT_OPERATOR;
            else if (value == ">")
                this.type = TokenType.GT_OPERATOR;
            else if (value == "<=")
                this.type = TokenType.LTE_OPERATOR;
            else if (value == ">=")
                this.type = TokenType.GTE_OPERATOR;

            // Shorthands
            else if (value == "+=")
                this.type = TokenType.PLUS_EQUALS_OPERATOR;
            else if (value == "-=")
                this.type = TokenType.MINUS_EQUALS_OPERATOR;
            else if (value == "/=")
                this.type = TokenType.DIV_EQUALS_OPERATOR;
            else if (value == "/~=")
                this.type = TokenType.FLOAT_DIV_EQUALS_OPERATOR;
            else if (value == "%=")
                this.type = TokenType.MOD_EQUALS_OPERATOR;

            else if (value == ">>=")
                this.type = TokenType.SHIFT_RIGHT_EQUALS_OPERATOR;
            else if (value == "<<=")
                this.type = TokenType.SHIFT_LEFT_EQUALS_OPERATOR;
            else if (value == "|=")
                this.type = TokenType.BITWISE_OR_EQUALS_OPERATOR;
            else if (value == "&=")
                this.type = TokenType.BITWISE_AND_EQUALS_OPERATOR;
            else if (value == "~=")
                this.type = TokenType.BITWISE_INVERT_EQUALS_OPERATOR;
            else if (value == "^=")
                this.type = TokenType.XOR_EQUALS_OPERATOR;
        }
        default:
            {
                throw new Error("Unknown token type " + value);
            }
    }
}