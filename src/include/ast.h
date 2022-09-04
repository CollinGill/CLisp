#pragma once

#include <unordered_set>
#include <vector>
#include "token.h"

namespace node
{
    typedef struct Node
    {
        token::Token tok;
        Node* parent;
        std::vector<Node*> children;
    } Node;

    Node* create_node(token::Token& tok);
}

class AST
{
public:
    AST();

    void generate_tree(std::vector<token::Token>& token_list);

private:
    node::Node* root;
    std::unordered_set<token::Type> operators;
};