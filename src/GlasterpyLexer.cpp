#include "GlasterpyLexer.hpp"

std::vector<Token> GlasterpyLexer::lex(char *line, int len)
{
    validate_identifier(line, len);
    return std::vector<Token>(); 
}

bool GlasterpyLexer::validate_identifier(char *line, int len)
{

    if(len < 1) {
        return false;
    }
    
    char *temp = new char[2]; 
    temp[1] = '\0';
    temp = (char*)utf8proc_NFKC((utf8proc_uint8_t*)line);
    //std::cout << line << std::endl;
    std::cout << temp << std::endl;

    return false;
}