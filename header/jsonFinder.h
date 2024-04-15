#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>

struct Entry {
    std::string type;
    std::string key;
    std::string value;
    std::string command;
    std::string path;
};

class Reader {
public:
    std::string outputfile; // Variable zum Speichern des Wertes von "outputfile"
    bool hideshell; // Variable zum Speichern des Wertes von "hideshell"
    std::string application; // Variable zum Speichern des Pfads und Namens der auszuführenden Anwendung
    Json::Value root;
    Json::Reader reader;

    // Funktion zum Lesen einer JSON-Datei
    void readJSON(char const *argv) {
        std::string fileName = argv;
        std::cout << fileName << std::endl;
        // Öffnen der Datei aus der Benutzereingabe
        std::ifstream file(argv);
        file >> root;
        std::cout << root << std::endl;
        // Überprüfen, ob die Datei geöffnet wurde
        if (file.is_open()) {
            const Json::Value outputfileValue = root[0]["outputfile"];
            const Json::Value hideshellValue = root[0]["hideshell"];
            const Json::Value applicationValue = root[0]["application"];
            const Json::Value entries = root[0]["entries"];

            // Überprüfe, ob der Wert korrekt ausgelesen wurde
            if (!outputfileValue.isNull())
            {
                std::cout << "Der Wert von outputfile ist: " << outputfileValue.asString() << std::endl;
                std::cout << "Der Wert von hideshell ist: " << hideshellValue.asString() << std::endl;
                std::cout << "Der Wert von application ist: " << applicationValue.asString() << std::endl;

                for (const auto& entry : entries) {
                    Entry newEntry;
                    newEntry.type = entry["type"].asString();
                    if (newEntry.type == "ENV") {
                        newEntry.key = entry["key"].asString();
                        newEntry.value = entry["value"].asString();
                    } 
                    else if (newEntry.type == "EXE") {
                        newEntry.command = entry["command"].asString();
                    } 
                    else if (newEntry.type == "PATH") {
                        newEntry.path = entry["path"].asString();
                    }
                    entries.append(newEntry);
            }
                /*for ( int index = 0; index < entries.size(); ++index ){
                    std::cout << "Der Wert an Stelle " << index + 1 << " ist: " << entries[index] << std::endl;
                    }*/
            }
            else
            {
                std::cout << "Fehler beim Lesen von outputfile" << std::endl;
            }
            // Schließen der Datei nach Abschluss

            file.close();
        } else {
            std::cout << "File " << argv << " does not exist or the path is wrong" << "\n";
        }
    }

    // Function to determine if the user inputs ends in json 
    bool endsWithJson(std::string fileName, std::string targetEnding) {
        std::cout << "Filename: " << fileName << "\n";
        // Compare if the user input file has less letters then the target: ".json"
        if(targetEnding.size() > fileName.size()) {
            std::cout << "Filename: " << fileName << " does not end in .json" << "\n";
            // Return false if so
            return false;
        }
        // Comparing both strings and return true if they are equal to 0 (they compare equal)
        return fileName.compare(fileName.size() - targetEnding.size(), targetEnding.size(), targetEnding) == 0;
    }
};
