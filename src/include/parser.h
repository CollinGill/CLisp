#pragma once

#include <assert.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "ast.h"
#include "token.h"

using namespace token;

class Parser
{
public:
    Parser();

    void parse(std::string &file);
    void evaluate();

    std::string read_file(std::string &file_name);

    std::vector<Token> get_token_list();
    void clear();
    void print_tokens();

private:
    AST ast;

    void tokenize(std::string &file);
    std::vector<Token> token_list;
    std::unordered_set<char> special_chars;

    inline bool is_int(std::string &str);
    inline bool is_float(std::string &str);

    void eval_ast(node::Node *rt);
    token::Token eval_list(std::vector<node::Node*> &children);
};