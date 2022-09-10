#pragma once

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>

namespace token
{
    enum Type
    {
        NONE,
        ERROR,

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
    
    inline std::unordered_set<token::Type> operators = {PLUS, MINUS, MULTIPLY, DIVIDE, MODULO};

    std::string readable_type(Type type);

    class Token
    {
    public:
        Token(Type type, std::string val);

        Type get_type();
        std::string get_val();

        void set_type(Type type);
        void set_val(std::string& val);

        void print();
        
    private:
        Type type;
        std::string val;
    };
}