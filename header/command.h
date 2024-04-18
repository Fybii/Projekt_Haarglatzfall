#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    int option;
    int i = 1;
    
    bool checkInput(std::string opt, char shortopt, std::string longopt);
    bool checkInput(std::string opt, std::string longopt);
};

class Help : public Command {
public:
    static const char * const HELPTEXT;
    void showHelpText();
};

#endif
