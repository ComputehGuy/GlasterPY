#include <iostream>
#include <unistd.h>

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
            //GlasterpyLexer::lex(script.currentLine, script.len);
            std::cout << script.len << std::endl;
            std::cout << script.currentLine << std::endl;
            break;
        }
        // GlasterpyLexer::lex(script.currentLine, script.len);
    }

    return 0;
}