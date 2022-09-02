#include "./include/parser.h"

Parser::Parser()
{
    token_list = std::vector<token::Token>();
}

std::string Parser::read_file(std::string& file_name)
{
    std::ifstream file {file_name};
    std::string file_txt = "";
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line))
            file_txt.append(line);

        return file_txt;

    } else {
        std::cout << "ERROR: Unable to open file `" << file_name << "`\n";
        assert(false);
    }
}