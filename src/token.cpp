#include "./include/token.h"

using namespace token;

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