#pragma once

#include <assert.h>
#include <fstream>
#include <unordered_set>
#include <vector>
#include "token.h"

using namespace token;

class Parser
{
public:
    Parser();

    std::string read_file(std::string& file_name);
    void tokenize(std::string& file);

    std::vector<Token> get_token_list();
    void print_tokens();

private:
    std::vector<Token> token_list;
    std::unordered_set<char> special_chars;
};