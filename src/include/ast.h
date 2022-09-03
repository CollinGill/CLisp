#pragma once

#include <memory>
#include <vector>
#include "token.h"

typedef struct Node
{
    token::Token tok;
    std::vector<std::unique_ptr<Node>> children;
} Node;

class AST
{
public:
    AST();

    void generate_tree();

private:
    std::unique_ptr<Node> root;
};