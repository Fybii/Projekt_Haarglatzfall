#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include "../src/jsonClass.cpp"

// struct Entry {
//     std::string type;
//     std::string key;
//     std::string value;
//     std::string command;
//     std::string path;
//     std::string entryArray[100];
// };

class Reader {
public:
    std::string outputfile; // Variable zum Speichern des Wertes von "outputfile"
    bool hideshell; // Variable zum Speichern des Wertes von "hideshell"
    std::string application; // Variable zum Speichern des Pfads und Namens der auszuführenden Anwendung
    Json::Value root;
    ENV env;
    EXE exe;
    PATH path;
    
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
            std::string entryArray[100][1];

            // Überprüfe, ob der Wert korrekt ausgelesen wurde
            if (!outputfileValue.isNull())
            {
                std::cout << "Der Wert von outputfile ist: " << outputfileValue.asString() << std::endl;
                std::cout << "Der Wert von hideshell ist: " << hideshellValue.asString() << std::endl;
                std::cout << "Der Wert von application ist: " << applicationValue.asString() << std::endl;

                for (const auto& entry : entries) {
                    Entry newEntry;
                    if (entry["type"].asString() == "ENV") {
                        env.type = entry["type"].asString();
                        env.key = entry["key"].asString();
                        env.value = entry["value"].asString();
                        env.pushValueInArray(env, env.index);
                        std::cout << "env Ausgabe: \n Zeile: " << env.index << " Spalte 1:\n" << env.array[env.index][0] << "\n";
                        std::cout << "Zeile: " << env.index << " Spalte 2:\n" << env.array[env.index][1] << "\n";
                        std::cout << "Zeile: " << env.index << " Spalte 3:\n" << env.array[env.index][2] << "\n";
                        env.index++;
                    } 
                    else if (newEntry.type == "EXE") {
                        exe.type = entry["type"].asString();
                        exe.command = entry["command"].asString();
                        exe.pushValueInArray(exe, exe.index);
                        std::cout << "exe Ausgabe: \n Zeile: " << exe.index << " Spalte 1:\n" << exe.array[exe.index][0] << "\n";
                        std::cout << "Zeile: " << exe.index << " Spalte 2:\n" << exe.array[exe.index][1] << "\n";
                        exe.index++;
                    } 
                    else if (newEntry.type == "PATH") {
                        path.type = entry["type"].asString();
                        path.path = entry["path"].asString();
                        path.pushValueInArray(path, path.index);
                        std::cout << "exe Ausgabe: \n Zeile: " << path.index << " Spalte 1:\n" << path.array[path.index][0] << "\n";
                        std::cout << "Zeile: " << path.index << " Spalte 2:\n" << path.array[path.index][1] << "\n";
                        path.index++;
                    }     
                }
            }
            else
            {
                std::cout << "Fehler beim Lesen von outputfile" << std::endl;
            }
            // Schließen der Datei nach Abschluss

            file.close();
        } 
        else {
            std::cout << "File " << argv << " does not exist or the path is wrong" << "\n";
        }
    }

    std::string arrayIteration(std::string tempArray[], std::string entryArray[][1], int indexI, int indexJ) {
        for(int j = 0; j < indexJ; j++) {
            std::cout << entryArray[indexI][indexJ];
            entryArray[indexI][indexJ] = tempArray[indexJ];
            std::cout << "Stelle: " << indexI + " " + indexJ << "|||" + entryArray[indexI][indexJ] << "\n";
        }
        return entryArray[indexI][indexJ];
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
