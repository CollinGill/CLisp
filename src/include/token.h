#pragma once

#include <iostream>
#include <string>
#include <tuple>

namespace token
{
    enum Type
    {
        NONE,

        // Semantics
        LPAREN,
        RPAREN,
        LIST,

        // Data types
        STRING_LITERAL,
        INTEGER,
        FLOAT,
        WORD,

        // Operators
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        MODULO
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