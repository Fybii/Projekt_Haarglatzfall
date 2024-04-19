#ifndef JSON_FINDER
#define JSON_FINDER

#include "jsonClass.h" // Include, falls benötigt
#include <jsoncpp/json/json.h>
#include <string>

class JsonReader {
public:
    std::string outputfile; // Variable zum Speichern des Wertes von "outputfile"
    bool hideshell; // Variable zum Speichern des Wertes von "hideshell"
    std::string application; // Variable zum Speichern des Pfads und Namens der auszuführenden Anwendung
    Json::Value outputfileValue;
    Json::Value hideshellValue;
    Json::Value applicationValue;
    Json::Value entries;
    ENV env; // Deklaration der Variable env vom Typ ENV
    EXE exe; // Deklaration der Variable exe vom Typ EXE
    PATH path; // Deklaration der Variable path vom Typ PATH

    // Funktion zum Lesen einer JSON-Datei
    void readJSON(const char* argv);
    // Function to determine if the user inputs ends in json 
    bool endsWithJson(std::string fileName, std::string targetEnding);
    static bool check_types(std::string path);
};

#endif
