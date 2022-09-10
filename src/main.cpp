#include "./include/parser.h"
#include "./include/shell.h"

int main(int argc, char* argv[])
{
    std::vector<std::string> args {argv, argv + argc};
    
    // checking if a yal file was passed as an argument
    if (argc > 1) {
        // Interpret code
        if (argc > 2) {
            std::cout << "Sorry, Yal only supports single files at this time\n";
            return -1;
        } else {
            Parser parser { Parser() };
            std::string file { parser.read_file(args[1]) };
            parser.parse(file);
            parser.evaluate();
        }

    } else {
        // Open interpreter shell 
        Shell shell { Shell() };
        shell.run();
    }

    return 0;
}