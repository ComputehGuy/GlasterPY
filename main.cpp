#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "GlasterpyScrypt.hpp"
#include "GlasterpyLexer.hpp"

int main(int argc, char **argv)
{

    GlasterpyScrypt script(argv[1]);
    while(true) {

        try {
            script.getLine();
        }

        catch(const std::exception& e) {
            std::cout << "script.len: " << script.len << std::endl;
            GlasterpyLexer::lex(script.currentLine, script.len);
            break;
        }

    }

    return 0;
}