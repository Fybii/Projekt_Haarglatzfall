#include "jsonFinder.h"
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include "jsonClass.h"
#include "createBatch.h"

// function to read json data
// ReqFunc 5
void JsonReader::readJSON(const char* argv) {
    std::string fileName = argv;
    if (check_types(fileName)) {
        // open json file from user input
        std::ifstream file(argv);
        Json::Value root;
        file >> root;
        // check if json file is opened correctely if not error
        if (file.is_open()) {
            // save values (outputfile, hideshell, application) from given json file 
            outputfileValue = root["outputfile"]; // ReqFunc8
            hideshellValue = root["hideshell"]; // ReqFunc9
            applicationValue = root["application"]; // ReqFunc16
            entries = root["entries"]; // ReqFunc10
            std::string envArray[100][3];

            // check if json file has value
            if (!outputfileValue.isNull()) {
                for (const auto& entry : entries) {
                    // if block to check which entry type it is
                    if (entry["type"].asString() == "ENV") { // ReqFunc 11; if ENV type is given, save key and value in class ENV array 
                        env.type = entry["type"].asString();
                        env.key = entry["key"].asString();
                        env.value = entry["value"].asString();
                        env.array[env.index][0] = env.type; // Req Func 15
                        env.array[env.index][1] = env.key;
                        env.array[env.index][2] = env.value;
                        env.index++;
                    } 
                    else if (entry["type"].asString() == "EXE") { // ReqFunc 12;  if EXE type is given, save command in class EXE array 
                        exe.type = entry["type"].asString();
                        exe.command = entry["command"].asString();
                        exe.array[exe.index][0] = exe.type; // Req Func 15
                        exe.array[exe.index][1] = exe.command;
                        exe.index++;
                    } 
                    else if (entry["type"].asString() == "PATH") { // ReqFunc 13; if PATH type is given, save path in class PATH array 
                        path.type = entry["type"].asString();
                        path.path = entry["path"].asString();
                        path.array[path.index][0] = path.type; // Req Func 15
                        path.array[path.index][1] = path.path;
                        path.index++;
                    }     
                }
                env.index = 0;
                exe.index = 0;
                path.index = 0;
            }
            else {
                std::cout << "Fehler beim Lesen von outputfile" << std::endl;
            }
            // Closing the file upon completion     

            file.close();
        } 
        else {
            if(argv == "-h" || argv == "--help") {
                exit(0);
            }
            else {
            std::cout << "File " << argv << " does not exist or the path is wrong" << "\n";
            }
        }
    }
}

// Function to determine if the user inputs ends in json 
bool JsonReader::endsWithJson(std::string fileName, std::string targetEnding) {
    // Compare if the user input file has less letters then the target: ".json"
    if (targetEnding.size() > fileName.size()) {
        // Return false if so
        return false;
    }
    // Comparing both strings and return true if they are equal to 0 (they compare equal)
    return fileName.compare(fileName.size() - targetEnding.size(), targetEnding.size(), targetEnding) == 0;
}

//Function to check if the given Json data is open
//ReqFunc 6
bool JsonReader::check_types(std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Fehler: Die JSON Datei konnte nicht gefunden werden oder sie existiert nicht" << std::endl;
        exit(0);
        return false;
    }

    std::string line;
    int lineNumber = 0;

    // Req Func 17
    // Read the JSON file line by line and check if the entries are right
    while (getline(file, line)) {
        lineNumber++;
        if (line.find("type") != std::string::npos) {
            if (line.find("EXE") == std::string::npos && line.find("ENV") == std::string::npos && line.find("PATH") == std::string::npos) {
                std::cerr << "Der Typ in Zeile " << lineNumber << " ist fehlerhaft" << std::endl;
                return false;
            }
        }
    }
    return true;
}
