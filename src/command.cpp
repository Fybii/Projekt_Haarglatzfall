#include "command.h"
#include <iostream>

// Req 1, 2, 3
// Definition and initialization of the static constant HELPTEXT
const char * const Help::HELPTEXT = "+--------programm help-------+\n"
                                    "Welcome to the help overlay!\n"
                                    "This Programm reads a JSON Data and converts it into an executable batch file.\n"
                                    "To start the Programm write './build/JsonToBatch' into the terminal and enter the name of your JSON Data right after it.\nIf you need any help with the programm you can contact us through 'rittinger.mori-it23@it.dhbw-ravensburg.de'\n"
                                    "Our Team: Max Engelhardt, Ruth Fröhlich, Fabian Peifer, Moritz Rittinger\n\n"
                                    "Commands:\n"
                                    "-h/--help: A command to show the function of this programm and explain every command";

// Implementation of the function to check input for short and long options
bool Command::checkInput(std::string opt, char shortopt, std::string longopt) {
    bool validInput = false; // Boolean variable to give output: true or false
    std::string option = ""; // Set a string and convert the option char to string
    option.push_back(shortopt);
    // Check if the user input is equivalent to the accepted inputs
    if (opt == "-" + option || opt == longopt) {
        validInput = true; // If true, set the boolean to true
    }
    return validInput; // Return the boolean value
}

// Implementation of the function to check input for only long options
bool Command::checkInput(std::string opt, std::string longopt) {
    bool validInput = false; // Boolean variable to give output: true or false
    // Check if the user input is equivalent to the accepted long option
    if (opt == longopt) {
        validInput = true; // If true, set the boolean to true
    }
    return validInput; // Return the boolean value
}

// Implementation of the function to display the help text
void Help::showHelpText() {
    std::cout << HELPTEXT << std::endl; // Output the help text
}
