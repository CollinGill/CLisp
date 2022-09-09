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
    operators = {token::Type::PLUS, token::Type::MINUS, token::Type::MULTIPLY, token::Type::DIVIDE, token::Type::MODULO};
    token::Token null_tok = token::Token(token::Type::NONE, "");
    root = node::create_node(null_tok);
}

AST::~AST()
{
    // Go through tree and free the nodes
}

void AST::generate_tree(std::vector<token::Token> &token_list)
{
    // Assuming the list starts with '('

    node::Node* cur = root;
    cur->tok = token::Token(token::Type::LIST, "");

    for (std::size_t i = 1; i < token_list.size(); i++) {
        token::Token tok {token_list.at(i)};
        
        if (tok.get_type() == token::LPAREN) {
            token::Token list = token::Token(token::Type::LIST, "");
            cur->children.push_back(node::create_node(list));
            cur->children[cur->children.size() - 1]->parent = cur;
            cur = cur->children[cur->children.size() - 1];

        } else if (tok.get_type() == token::RPAREN) {
            if (cur->parent == nullptr)
                break;
            cur = cur->parent;

        } else {
            cur->children.push_back(node::create_node(tok));
            cur->children[cur->children.size() - 1]->parent = cur;
        }
    }
    cur = nullptr;
    free(cur);
}

void AST::print()
{
    std::queue<node::Node*> bfs = std::queue<node::Node*>();
    bfs.push(root);

    while (!bfs.empty()) {
        node::Node* cur = bfs.front();
        node::print_node(cur);
        bfs.pop();
        for (auto child : cur->children)
            bfs.push(child);
    }
}
