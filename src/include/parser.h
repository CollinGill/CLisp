#pragma once

#include <assert.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "token.h"

using namespace token;

class Parser
{
public:
    Parser();

    std::string read_file(std::string& file_name);
    void parse_file(std::string& file);

    std::vector<Token> get_token_list();

private:
    std::vector<Token> token_list;
};