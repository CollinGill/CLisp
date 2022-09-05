#include "./include/ast.h"

node::Node::Node(token::Token& tok):
    tok(tok)
{
    this->parent = nullptr;
    this->children = std::vector<Node*>();
}

node::Node *node::create_node(token::Token &tok)
{
    Node* new_node = new Node(tok);
    return new_node;
}

void node::print_node(node::Node* n)
{
    n->tok.print();
}

AST::AST()
{
    operators = {token::PLUS, token::MINUS, token::MULTIPLY, token::DIVIDE, token::MODULO};
}

AST::~AST()
{
    // Go through tree and free the nodes
}

void AST::generate_tree(std::vector<token::Token> &token_list)
{
    node::Node* cur = root;

    // Assuming the list starts with '('
    token::Token first_tok = token::Token(token::LIST, "");
    cur = node::create_node(first_tok);

    for (std::size_t i = 1; i < token_list.size(); i++)
    {
        token::Token tok {token_list.at(i)};
        cur->tok.print();
        if (tok.get_type() == token::LPAREN) {
            token::Token list_tok = token::Token(token::LIST, "");
            cur = node::create_node(list_tok);
        } else if (tok.get_type() == token::RPAREN){
            cur = cur->parent;
        } else {
            node::Node* tmp = node::create_node(tok);
            tmp->parent = cur;
            cur->children.push_back(tmp);
        }
    }
    cur = nullptr;
    free(cur);
}

void AST::print()
{
    node::print_node(root);
}