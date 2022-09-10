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

    while (running) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if ((input.compare("(exit)") == 0) || (input.compare("exit") == 0)) {
            running = false;
        } else {
            parser.parse(input);
        }
    }
}