#include "./include/shell.h"

Shell::Shell() 
{
    input = "";
    parser = Parser();
}

// TODO: support multi-line input once the interpreter is up to par
void Shell::run()
{
    bool running { true };
    std::string combined { "" };

    while (running) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input.compare("(exit)") == 0) {
            running = false;
        } else {
            combined.append(input);
            std::string::difference_type open { std::count(combined.begin(), combined.end(), '(') };
            std::string::difference_type closed { std::count(combined.begin(), combined.end(), ')') };
            if (open == closed) {
                parser.parse(combined);
                parser.evaluate();
                parser.clear();
                combined = "";
            }
        }
    }
}