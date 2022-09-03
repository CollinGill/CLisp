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
        QUOTE,
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
        //std::tuple<int, int> get_location();

        void set_type(Type type);
        //void set_position(int r, int c);
        void set_val(std::string& val);

        void print();
        
    private:
        Type type;
        std::string val;
        // int row;
        // int column;
    };
}