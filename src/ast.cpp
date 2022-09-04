#include "./include/ast.h"

node::Node* node::create_node(token::Token& tok)
{
    Node* new_node = (Node*) malloc(sizeof(Node*));
    new_node->tok = tok;
    new_node->parent = nullptr;
    new_node->children = std::vector<Node*>();
    return new_node;
}

AST::AST()
{
    operators = { token::PLUS, token::MINUS, token::MULTIPLY, token::DIVIDE, token::MODULO };
}

void AST::generate_tree(std::vector<token::Token>& token_list)
{
    node::Node* cur;
    bool root_tok { false };
    for (std::size_t i = 0; i < token_list.size(); i++) {
        token::Token tok { token_list.at(i) };
        if (!root_tok) {
            if (tok.get_type() == token::LPAREN) {
                continue;
            } else if (operators.find(tok.get_type()) != operators.end()) {
                root = node::create_node(tok);
                root_tok = true;
            }
        } else {
        }
    }
}