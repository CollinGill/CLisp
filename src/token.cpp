#include "./include/token.h"

using namespace token;

std::string token::readable_type(Type type)
{
    switch (type)
    {
        case LPAREN:
            return "LPAREN";
            break;

        case RPAREN:
            return "RPAREN";
            break;

        case QUOTE:
            return "QUOTE";
            break;

        case STRING_LITERAL:
            return "QUOTE";
            break;

        case INTEGER:
            return "INTEGER";
            break;

        case FLOAT:
            return "FLOAT";
            break;

        case PLUS:
            return "PLUS";
            break;

        case MINUS:
            return "MINUS";
            break;

        case MULTIPLY:
            return "MULTIPLY";
            break;

        case DIVIDE:
            return "DIVIDE";
            break;

        case MODULO:
            return "MODULO";
            break;

        case WORD:
            return "WORD";
            break;

        default:
            return "ERROR";
    }
} 

Token::Token(Type type, std::string val)
{
    set_type(type);
    //set_position(row, column);
    set_val(val);
}


Type Token::get_type()
{
    return type;
}


/*
std::tuple<int, int> Token::get_location()
{
    return std::make_tuple(row, column);
}
*/

void Token::set_type(Type type)
{
    this->type = type;
}

/*
void Token::set_position(int r, int c)
{
    this->row = r;
    this->column = c;
}
*/

void Token::set_val(std::string& val)
{
    this->val = val;
}

void Token::print()
{
    std::cout << "[" << readable_type(type) << " | " << val << "]";
}