#ifndef JSON_FINDER
#define JSON_FINDER

#include "jsonClass.h"
#include <jsoncpp/json/json.h>
#include <string>

class JsonReader {
public:
    std::string outputfile; // Variable to save value "outputfile"
    bool hideshell; // Variable to save value "hideshell"
    std::string application; // Variable to save value "application"
    Json::Value outputfileValue;
    Json::Value hideshellValue;
    Json::Value applicationValue;
    Json::Value entries;
    ENV env; // Declare variable env form type ENV
    EXE exe; // Declare variable env form type EXE
    PATH path; // Declare variable env form type PATH

    // Function to read JSON Data
    void readJSON(const char* argv);
    // Function to determine if the user inputs ends in json 
    bool endsWithJson(std::string fileName, std::string targetEnding);
    static bool check_types(std::string path);
};

#endif
