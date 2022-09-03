#pragma once

#include <iostream>
#include <string>
#include <tuple>

namespace token
{
    enum Type
    {
        LPAREN,
        RPAREN,
        STRING_LITERAL,
        INTEGER,
        FLOAT,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        MODULO,
        WORD
    };

    std::string readable_type(Type type);

    class Token
    {
    public:
        Token(Type type, std::string val);

        Type get_type();

        void set_type(Type type);
        void set_val(std::string& val);

        void print();
        
    private:
        Type type;
        std::string val;
    };
}