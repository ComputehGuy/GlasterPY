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
            break;
        }
    }

    return 0;
}