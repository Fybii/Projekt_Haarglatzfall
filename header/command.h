//class elements for all commands
class Command {
    public:
        int option;
        int i = 1;
    //Function to check if the input from the user is correct: For one short and one long valid options
    //parameters needed: Input from the user, option variable from getopts, acceptet longopts command  
    bool checkInput(std::string opt, char shortopt, std::string longopt) {
        //bool variable to give outout: true or false
        bool validInput = false;
        //set a string and convert the option char to string
        std::string option = "";
        option = shortopt;
        //check if the user input is equivalent to the accepted inputs
        if(opt == "-" + option || opt == longopt) {
            //If true set the boolean on true and return it
            validInput = true;
            return validInput;
        }
        //If false return the flase boolean
        else return validInput;
    }

    //Function to check if the input from the user is correct: For only longopts
    bool checkInput(std::string opt, std::string longopt) {
        bool validInput = false;
        if(opt == longopt) {
            validInput = true;
            return validInput;
        }
        else return validInput;
    }

};

//Class for the help option
class Help : public Command {
    public:
        //Help text that will be outputed
        const char * const HELPTEXT = { 
            "+--------programm help-------+\n"
            "Welcome to the help overlay!\n"
            "..."
            };
    //Function to display the text
    void showHelpText() {
        puts(HELPTEXT);
        exit(0);
    }
};

