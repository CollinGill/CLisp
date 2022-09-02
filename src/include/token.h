#pragma once

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
        FLOAT
    };

    class Token
    {
    public:
        Token(Type type, int row, int column, std::string& val);

        Type get_type();
        std::tuple<int, int> get_location();

        void set_type(Type type);
        void set_position(int r, int c);
        void set_val(std::string& val);
        
    private:
        Type type;
        std::string val;
        int row;
        int column;
    };
}