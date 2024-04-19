#ifndef JSON_FINDER
#define JSON_FINDER 

#include <fstream>
#include <filesystem>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsonClass.h>


// struct Entry {
//     std::string type;
//     std::string key;
//     std::string value;
//     std::string command;
//     std::string path;
//     std::string entryArray[100];
// };

class JsonReader {
public:
    std::string outputfile; // variable to save of value of "outputfile" from JSON
    bool hideshell; // variable to save of value of "hideshell" from JSON 
    std::string application; // variable to save of value of "application" from JSON
    Json::Value root; //variable for saving values from JSON file in other variables
    ENV env; // object of class ENV to save Values from "entries" with type "ENV" from JSON
    EXE exe; // object of class EXE to save Values from "entries" with type "EXE" from JSON
    PATH path; // object of class PATH to save Values from "entries" with type "PATH" from JSON
    
    // function to parse JSON file and save Values in predefined variables
    void readJSON(char const *argv) {
        std::string fileName = argv;
        if(check_types(fileName)) {
            std::cout << fileName << std::endl; // output of filename (for debugging)
            std::ifstream file(argv); // open file from user input
            file >> root;
            std::cout << root << std::endl;
            if (file.is_open()) { //check if JSON file is opened correctly
                const Json::Value outputfileValue = root[0]["outputfile"]; //save value from JSON file with property name "outputfile" in predefined variable 
                const Json::Value hideshellValue = root[0]["hideshell"]; //save value from JSON file with property name "hideshell" in predefined variable 
                const Json::Value applicationValue = root[0]["application"]; //save value from JSON file with property name "application" in predefined variable 
                const Json::Value entries = root[0]["entries"]; //save all the values from JSON with property names "entries"
                std::string envArray[100][3]; // array for saving values 

                // Überprüfe, ob der Wert korrekt ausgelesen wurde
                if (!outputfileValue.isNull())
                {
                    std::cout << "Der Wert von outputfile ist: " << outputfileValue.asString() << std::endl; // debugging purpose
                    std::cout << "Der Wert von hideshell ist: " << hideshellValue.asString() << std::endl; // debugging purpose
                    std::cout << "Der Wert von application ist: " << applicationValue.asString() << std::endl; // debugging purpose
                    for (const auto& entry : entries) { // for loop to go through "entries"
                        if (entry["type"].asString() == "ENV") { // decide which entry type it is
                            env.type = entry["type"].asString(); // convert values from JSON file into String
                            env.key = entry["key"].asString(); // convert values from JSON file into String
                            env.value = entry["value"].asString(); // convert values from JSON file into String
                            env.array[env.index][0] = env.type; // save values in variables
                            env.array[env.index][1] = env.key; // save values in variables
                            env.array[env.index][2] = env.value; // save values in variables
                            std::cout << "env Ausgabe: \nZeile: " << env.index << " Spalte 1:\n" << env.array[env.index][0] << "\n"; // debugging purpose
                            std::cout << "Zeile: " << env.index << " Spalte 2:\n" << env.array[env.index][1] << "\n"; // debugging purpose
                            std::cout << "Zeile: " << env.index << " Spalte 3:\n" << env.array[env.index][2] << "\n"; // debugging purpose
                            env.index++;
                        } 
                        else if (entry["type"].asString() == "EXE") { // decide which entry type it is
                            exe.type = entry["type"].asString(); // convert values from JSON file into String
                            exe.command = entry["command"].asString(); // convert values from JSON file into String
                            exe.array[exe.index][0] = exe.type; // save values in variables
                            exe.array[exe.index][1] = exe.command; // save values in variables
                            std::cout << "exe Ausgabe: \nZeile: " << exe.index << " Spalte 1:\n" << exe.array[exe.index][0] << "\n"; // debugging purpose
                            std::cout << "Zeile: " << exe.index << " Spalte 2:\n" << exe.array[exe.index][1] << "\n"; // debugging purpose
                            exe.index++;
                        } 
                        else if (entry["type"].asString() == "PATH") { // decide which entry type it is
                            path.type = entry["type"].asString(); // convert values from JSON file into String
                            path.path = entry["path"].asString(); // convert values from JSON file into String
                            path.array[path.index][0] = path.type; // save values in variables
                            path.array[path.index][1] = path.path; // save values in variables
                            std::cout << "path Ausgabe: \nZeile: " << path.index << " Spalte 1:\n" << path.array[path.index][0] << "\n"; // debugging purpose
                            std::cout << "Zeile: " << path.index << " Spalte 2:\n" << path.array[path.index][1] << "\n"; // debugging purpose
                            path.index++;
                        }     
                    }
                    std::cout << env.array[1][0] << "\n"; // debugging purpose
                    std::cout << env.array[1][1] << "\n"; // debugging purpose
                    std::cout << env.array[1][2] << "\n"; // debugging purpose
                }
                else
                {
                    std::cout << "Fehler beim Lesen von outputfile" << std::endl; // errorcommand
                }

                file.close(); // close file after everythings finished
            } 
            else {
                std::cout << "File " << argv << " does not exist or the path is wrong" << "\n"; // errorcommand
            }
        }
    }

    // Function to determine if the user inputs ends in json 
    bool endsWithJson(std::string fileName, std::string targetEnding) {
        std::cout << "Filename: " << fileName << "\n"; // debugging purpose
        // Compare if the user input file has less letters then the target: ".json"
        if(targetEnding.size() > fileName.size()) {
            std::cout << "Filename: " << fileName << " does not end in .json" << "\n"; // errorcommand
            return false;
        }
        // Comparing both strings and return true if they are equal to 0 (they compare equal)
        return fileName.compare(fileName.size() - targetEnding.size(), targetEnding.size(), targetEnding) == 0;

    }
    static bool check_types(std::string path)
{
    std::ifstream file(path); // debugging purpose
    if (!file.is_open())
    {
        std::cerr << "Fehler: Die JSON Datei kann nicht geöffnet werden" << std::endl; // errorcommand
        return false;
    }

    std::string line; // variable for iteration through JSON
    int lineNumber = 0; // start at the beginning/ value = 0

    // Read the JSON file line by line
    while (getline(file, line))
    {
        lineNumber++; // increment to go 1 line further


        if (line.find("type") != std::string::npos) // if incorrect type is given
        {
            if (line.find("EXE") == std::string::npos && line.find("ENV") == std::string::npos && line.find("PATH") == std::string::npos)
            {
                std::cerr << "Der Typ in Zeile " << lineNumber << " ist fehlerhaft" << std::endl; // errorcommand to stop programm and return the incorrect line number
                return false;
            }
        }
    }
    return true;
}
};

#endif   
