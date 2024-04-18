#include "command.h"
#include <iostream>

// Definition und Initialisierung der statischen Konstanten HELPTEXT
const char * const Help::HELPTEXT = "+--------programm help-------+\nWelcome to the help overlay!\n...";

bool Command::checkInput(std::string opt, char shortopt, std::string longopt) {
    bool validInput = false;
    std::string option = "";
    option.push_back(shortopt);
    if(opt == "-" + option || opt == longopt) {
        validInput = true;
    }
    return validInput;
}

bool Command::checkInput(std::string opt, std::string longopt) {
    bool validInput = false;
    if(opt == longopt) {
        validInput = true;
    }
    return validInput;
}

void Help::showHelpText() {
    std::cout << HELPTEXT << std::endl;
}
