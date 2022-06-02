#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

class GlasterpyScrypt
{

    public:
        char *currentLine;
        int len = 0;
        std::ifstream script;

        GlasterpyScrypt();
        GlasterpyScrypt(const char *FileName);

        ~GlasterpyScrypt();

        void getLine();

};

class EndOfFile : public std::exception
{ 
    public:  
        const char* what() const throw()  
        {  
            return "Hit End Of Script.\n"; 
        }  
};  