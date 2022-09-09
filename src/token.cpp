#include "./include/token.h"

using namespace token;

std::string token::readable_type(Type type)
{
    switch (type)
    {
        case LPAREN:
            return "LPAREN";

        case RPAREN:
            return "RPAREN";

        case LIST:
            return "LIST";

        case STRING_LITERAL:
            return "QUOTE";

        case INTEGER:
            return "INTEGER";

        case FLOAT:
            return "FLOAT";

        case WORD:
            return "WORD";

        case PLUS:
            return "PLUS";

        case MINUS:
            return "MINUS";

        case MULTIPLY:
            return "MULTIPLY";

        case DIVIDE:
            return "DIVIDE";

        case MODULO:
            return "MODULO";

        default:
            return "ERROR";
    }
} 

Token::Token(Type type, std::string val)
{
    set_type(type);
    set_val(val);
}


Type Token::get_type()
{
    return type;
}

void Token::set_type(Type type)
{
    this->type = type;
}

void Token::set_val(std::string& val)
{
    this->val = val;
}

void Token::print()
{
    if (type == LIST)
        std::cout << "[" << readable_type(type) << val << "]";
    else
        std::cout << "[" << readable_type(type) << " | " << val << "]";
}