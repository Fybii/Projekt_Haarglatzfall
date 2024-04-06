#include <fstream>
#include <iostream>

class Reader {
    public:
        //Function to read a json file
        void readJSON(char const *argv) {
            //open file the file from the user input
            std::ifstream in(argv);
            //if the file got opened do:
            if(in.is_open()) {
                std::string line;
                //loop to read every line in the json
                while(std::getline(in, line)) {
                    std::cout << line << "\n";
                }
                //clsoe the file after completion
                in.close();
            }
            else {
                std::cout << "File " << argv << " don't exist or the path is wrong" << "\n";
            }
        }

        //Function to determin if the user inputs ends in json 
        bool endsWithJson(std::string fileName, std::string targetEnding) {
            if (fileName == "") {
                exit(0);
            }
            std::cout << "Filename: " << fileName << "\n";
            //Compare if the user input file has less letters then the target: ".json"
            if(targetEnding.size() > fileName.size()) {
                std::cout << "Filename: " << fileName << " does not end in .json" << "\n";
                //return false if so
                return false;
            }
            //comparing both strings and return true if they are equal to 0 (they compare equal)
            return fileName.compare(fileName.size() - targetEnding.size(), targetEnding.size(), targetEnding) == 0;
        }
};