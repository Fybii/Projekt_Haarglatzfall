#include <iostream>
#include <getopt.h>
#include <fstream>
#include <string>
//including of the help file that will be displayed
#include "command.h"
#include "jsonClass.h"
#include "jsonFinder.h"
#include "createBatch.h"
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
        std::cerr << "Error: No File or command was given to the programm, Enter -h or --help to see the helpdesk\n";
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
                exit(0);
                }
                else {
                    std::cerr << "Error: Not a valid command, Enter -h or --help to see the helpdesk\n";
                    return 1;
                }
                break;
            
            default:
                std::cerr << "invalid Input, Enter -h or --help to see the helpdesk\n";
                break;
            };
        };
        //Loop to go through every JSON data the user wants to read
        //checks if the end of the file Name ends with ".json"
        while (1) {
            if(argv[i] != NULL) {
                if(!file.endsWithJson(argv[i], ".json")) {
                    std::cout << "Filename: " << argv[i] << " does not end in .json" << "\n";
                    exit(0);
                }
            }
            else {
                break;
            }
            //executes the readJSON function in jsonFinder.h
            file.readJSON(argv[i]);
            std::cout << "outputfile: " << file.outputfileValue << "\n";
            std::cout << "hideshell: " << file.hideshellValue << "\n";
            std::cout << "application: " << file.applicationValue << "\n";
            std::cout << "env: " << file.env.array[0][1];
            createBatchFile(file);
            
            //counts up to read next JSON data
            i++;
            //Checks if the next user input isn't NULL
        } 
    }
    return 0;
}


