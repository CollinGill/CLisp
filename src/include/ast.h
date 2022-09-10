#pragma once

#include <queue>
#include <vector>
#include "token.h"

namespace node
{
    typedef struct Node
    {
        Node(token::Token &tok);

        token::Token tok;
        Node *parent;
        std::vector<Node*> children;
    } Node;

    Node* create_node(token::Token& tok);
    void print_node(Node* n);
}

class AST
{
public:
    AST();
    ~AST();

    node::Node* get_root();

    void generate_tree(std::vector<token::Token> &token_list);
    void print();

private:
    node::Node* root;
};