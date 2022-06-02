#include "GlasterpyScrypt.hpp"

GlasterpyScrypt::GlasterpyScrypt()
{

    std::cout << "You have to specify a filename to open. An empty script object is useless. Exit." << std::endl;
    exit(1);

}

GlasterpyScrypt::GlasterpyScrypt(const char *FileName)
{

    script.open(FileName);

    currentLine = new char[0];

    if(!script) {
        std::cerr << "Couldn't open File: " << FileName << std::endl;
        exit(1);
    }

}

GlasterpyScrypt::~GlasterpyScrypt()
{
    this->script.close();
    delete[] currentLine;
}
/**
 * Gets the next line from the script and puts a pointer to the start of the line in the member variable currentLine.
 * throws EndOfFile if it hit end of file
 */
void GlasterpyScrypt::getLine()
{

    char buffer;
    std::string temp;
    len = 0;

    while (true) {

        if(script.eof()) {
            delete[] currentLine;
            currentLine = new char[temp.size() + 1];
            currentLine[temp.size()] = '\0';
            strncpy(currentLine, temp.c_str(), temp.size());
            this->len = temp.size() - 1;
            throw EndOfFile();
        }

        this->script.read(&buffer, 1);
        if(buffer == '\n') {
            delete[] currentLine;
            currentLine = new char[temp.size() + 1];
            currentLine[temp.size()] = '\0';
            strncpy(currentLine, temp.c_str(), temp.size());
            this->len = temp.size() - 1;
            return void();
        }

        temp.append(1, buffer);

    }
    
}
