#include "./include/parser.h"

Parser::Parser() 
{
    ast = AST();
    token_list = std::vector<token::Token>();
    special_chars = {'(', ')', '+', '-', '*', '/', '%'};
}

void Parser::parse(std::string& file)
{
    tokenize(file);
    ast.generate_tree(token_list);
    ast.print();
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

                // i = j so that on the next loop it skips the second quote symbol
                i = j;
                break;

            } else if ((last == ' ' || last == '\n' || last == '\t' || special_chars.find(last) != special_chars.end()) && !(in_quote)) {
                std::string word_name = file.substr(i, (j-i));
                token::Type tok_type = token::NONE;

                if (is_int(word_name))
                    tok_type = token::INTEGER;
                else
                    tok_type = token::WORD;

                token::Token tmp { tok_type, word_name };
                token_list.push_back(tmp);

                // i = j - 1 so that the next loop starts on the character that broke the word
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
    
inline bool Parser::is_int(std::string &str)
{
    if (str.empty() || 
        (((!std::isdigit(str[0]))) && 
         (str[0] != '-') && 
         (str[0] != '+')))

        return false;
    char *ptr;
    std::strtol(str.c_str(), &ptr, 10);
    
    return *ptr == 0;
}