#include <iostream>
#include <getopt.h>
#include <fstream>
#include <string>
//including of the help file that will be displayed
#include "command.h"
#include "jsonFinder.cpp"
//function to put the help text in the console
//test

//longopts structure which is used to use long operators as commands
struct option longopts[] = {
    //input: help, no argument is needed and safe as char 'h';
    {"help", no_argument, NULL, 'h'},
    {0, 0, 0, 0}
};

int main(int argc, char *argv[])
{
    int i = 1;
    //only start programm if user input is available 
    if(argc < 2) {
        std::cerr << "Error: No File or command was given to the programm\n";
    }
    else {
        //Set variables for the option char and index
        Help command;
        JsonReader file;
        //Loop for checking each command that is given by the user
        //Only activates if the user puts - or -- infront of command
        while ((command.option = getopt_long(argc, argv, "h", longopts, NULL)) != -1) {
            switch (command.option)
            {
            case 'h':
                if(command.checkInput(std::string(argv[command.i]), command.option, "--help")) {
                command.showHelpText();
                }
                else {
                    std::cerr << "Error: Not a valid command\n";
                    return 1;
                }
                break;
            
            default:
                std::cerr << "invalid Input\n";
                break;
            };
        };
        //Loop to go through every JSON data the user wants to read
        //checks if the end of the file Name ends with ".json"
        while (1) {
            if(argv[i] != NULL) {
                file.endsWithJson(argv[i], ".json");
            }
            else {
                break;
            }
            std::cout << argv[i] << " ends with json" << "\n";
            //executes the readJSON function in jsonFinder.h
            file.readJSON(argv[i]);
            //counts up to read next JSON data
            i++;
            //Checks if the next user input isn't NULL
        } 
        
    }
    return 0;
}


