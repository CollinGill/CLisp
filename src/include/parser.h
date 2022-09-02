#pragma once

#include <vector>
#include "token.h"

using namespace token;

class Parser
{
public:
    Parser();

private:
    std::vector<Token> token_list;
};