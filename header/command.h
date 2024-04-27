// ReqNonFunc 8
#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    int option; // Option variable
    int i = 1; // Counter variable

    // Function to check if the input from the user is correct: For one short and one long valid options
    // Parameters needed: Input from the user, option variable from getopts, accepted longopts command  
    bool checkInput(std::string opt, char shortopt, std::string longopt);

    // Function to check if the input from the user is correct: For only longopts
    bool checkInput(std::string opt, std::string longopt);
};

class Help : public Command {
public:
    static const char * const HELPTEXT; // Declaration of static constant for help text
    void showHelpText(); // Function to display the help text
};

#endif
