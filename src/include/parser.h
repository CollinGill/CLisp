#pragma once

#include <assert.h>
#include <fstream>
#include <vector>
#include "ast.h"
#include "token.h"

using namespace token;

class Parser
{
public:
    Parser();

    void parse(std::string& file);

    std::string read_file(std::string& file_name);

    std::vector<Token> get_token_list();
    void print_tokens();

private:
    AST ast;

    void tokenize(std::string& file);
    std::vector<Token> token_list;
    std::unordered_set<char> special_chars;
};