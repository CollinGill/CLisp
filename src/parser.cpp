#include "./include/parser.h"

Parser::Parser()
{
    token_list = std::vector<token::Token>();
    special_chars = {'(', ')', '+', '-', '*', '/', '%'};
}

std::string Parser::read_file(std::string& file_name)
{
    if (!(file_name.ends_with(".yal"))) {
        std::cout << "ERROR: file must end with '.yal'\n\n";
        assert(false);
    }

    std::ifstream file {file_name};
    std::string file_txt { "" };
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line))
            file_txt.append(line);

        return file_txt;

    } else {
        std::cout << "ERROR: Unable to open file `" << file_name << "`\n\n";
        assert(false);
    }
}

void Parser::tokenize(std::string& file)
{
    int paren_count { 0 };
    int quote_count { 0 };
    bool in_quote { false };
    
    for (std::size_t i = 0; i < file.size(); i++) {
        char first { file[i] };
        switch (first) {
            case '(':
            {
                paren_count++;
                token::Token tmp { token::Token(token::LPAREN, std::string(1, first)) };
                token_list.push_back(tmp);
                continue;
            }

            case ')':
            {
                paren_count--;

                if (paren_count < 0) {
                    std::cout << "ERROR: Unbalanced parenthesis\n";
                    assert(false);
                }
                token::Token tmp { token::Token(token::RPAREN, std::string(1, first)) };
                token_list.push_back(tmp);

                continue;
            }

            case ' ':
            case '\n':
            case '\t':
            {
                continue;
            }
            
            case '+':
            {
                token::Token tmp { token::Token(token::PLUS, std::string(1, first)) };
                token_list.push_back(tmp);
                continue;
            }

            case '-':
            {
                token::Token tmp { token::Token(token::MINUS, std::string(1, first)) };
                token_list.push_back(tmp);
                continue;
            }                

            case '*':
            {
                token::Token tmp { token::Token(token::MULTIPLY, std::string(1, first)) };
                token_list.push_back(tmp);
                continue;
            }

            case '/':
            {
                token::Token tmp { token::Token(token::DIVIDE, std::string(1, first)) };
                token_list.push_back(tmp);
                continue;
            }

            case '%':
            {
                token::Token tmp { token::Token(token::MODULO, std::string(1, first)) };
                token_list.push_back(tmp);
                continue;
            }

            case '"':
            {
                in_quote = !(in_quote);
                quote_count++;
                continue;
            }

            default:
                break;
        }

        // Iterate till end of word or file
        for (std::size_t j = i; i < file.size() && j < file.size(); j++) {
            char last { file[j] };

            if (last == '"') {
                in_quote = !(in_quote);
                quote_count--;
                if (quote_count < 0) {
                    std::cout << "ERROR: Unbalanced quotes\n";
                    assert(false);
                }

                token::Token tmp { token::Token(token::STRING_LITERAL, file.substr(i, (j-i))) };
                token_list.push_back(tmp);

                i = j;
                break;

            } else if ((last == ' ' || last == '\n' || last == '\t' || special_chars.find(last) != special_chars.end()) && !(in_quote)) {
                token::Token tmp { token::Token(token::WORD, file.substr(i, (j-i))) };
                token_list.push_back(tmp);

                i = j - 1;
                break;
            }
        }
    }

    if (paren_count != 0) {
        std::cout << "ERROR: EOF Unbalanced parenthesis\n";
        assert(false);
    }

    if (quote_count != 0) {
        std::cout << "ERROR: EOF Unbalanced quotes\n";
        assert(false);
    }
}

std::vector<token::Token> Parser::get_token_list()
{
    return token_list;
}

void Parser::print_tokens()
{
    for (auto token : token_list) {
        token.print();
        std::cout << std::endl;
    }
}