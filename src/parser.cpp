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

void Parser::parse_file(std::string& file)
{
    int paren_count { 0 };
    
    for (std::size_t i = 0; i < file.size(); i++) {
        char first { file[i] };
        switch (first) {
            case '(':
            {
                paren_count++;
                break;
            }

            case ')':
            {
                paren_count--;

                if (paren_count < 0) {
                    std::cout << "ERROR: Unbalanced parenthesis\n";
                    assert(false);
                }

                break;
            }

            case ' ':
            case '\n':
            case '\t':
            {
                continue;
                break;
            }
            
            case '+':
            {
                token::Token tmp { token::Token(token::PLUS, std::string(1, first)) };
                token_list.push_back(tmp);
                break;
            }

            case '-':
            {
                token::Token tmp { token::Token(token::MINUS, std::string(1, first)) };
                token_list.push_back(tmp);
                break;
            }                

            case '*':
            {
                token::Token tmp { token::Token(token::MULTIPLY, std::string(1, first)) };
                token_list.push_back(tmp);
                break;
            }

            case '/':
            {
                token::Token tmp { token::Token(token::DIVIDE, std::string(1, first)) };
                token_list.push_back(tmp);
                break;
            }

            case '%':
            {
                token::Token tmp { token::Token(token::MODULO, std::string(1, first)) };
                token_list.push_back(tmp);
                break;
            }

            default:
                break;
        }

        for (std::size_t j = i; j < file.size(); j++) {
            char last { file[j] };
        }
    }

    if (paren_count > 0) {
        std::cout << "ERROR: Unbalanced parenthesis\n";
        assert(false);
    }
}