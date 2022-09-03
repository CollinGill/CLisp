#pragma once

#include <iostream>
#include <string>
#include "parser.h"

class Shell
{
public:
    Shell();

    void run();

private:
    std::string input;
    Parser parser;
};