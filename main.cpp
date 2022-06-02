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
            for(int i = 0 ; i < script.len ; i ++) {
                std::cout << script.currentLine[i];
            }
            std::cout << std::endl;
            break;
        }

        for(int i = 0 ; i < script.len ; i ++) {
            std::cout << script.currentLine[i];
        }
        std::cout << std::endl;

    }

    return 0;
}