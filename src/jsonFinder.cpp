#include "jsonFinder.h"
#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include "jsonClass.h" // Include, falls benötigt
#include "createBatch.h"

// Funktion zum Lesen einer JSON-Datei
void JsonReader::readJSON(const char* argv) {
    std::string fileName = argv;
    if (check_types(fileName)) {
        std::cout << fileName << std::endl;
        // Öffnen der Datei aus der Benutzereingabe
        std::ifstream file(argv);
        Json::Value root;
        file >> root;
        std::cout << root << std::endl;
        // Überprüfen, ob die Datei geöffnet wurde
        if (file.is_open()) {
            outputfileValue = root["outputfile"];
            hideshellValue = root["hideshell"];
            applicationValue = root["application"];
            entries = root["entries"];
            std::string envArray[100][3];

            // Überprüfe, ob der Wert korrekt ausgelesen wurde
            if (!outputfileValue.isNull()) {
                std::cout << "Der Wert von outputfile ist: " << outputfileValue.asString() << std::endl;
                std::cout << "Der Wert von hideshell ist: " << hideshellValue.asString() << std::endl;
                std::cout << "Der Wert von application ist: " << applicationValue.asString() << std::endl;
                for (const auto& entry : entries) {
                    if (entry["type"].asString() == "ENV") {
                        env.type = entry["type"].asString();
                        env.key = entry["key"].asString();
                        env.value = entry["value"].asString();
                        env.array[env.index][0] = env.type;
                        env.array[env.index][1] = env.key;
                        env.array[env.index][2] = env.value;
                        std::cout << "env Ausgabe: \nZeile: " << env.index << " Spalte 1:\n" << env.array[env.index][0] << "\n";
                        std::cout << "Zeile: " << env.index << " Spalte 2:\n" << env.array[env.index][1] << "\n";
                        std::cout << "Zeile: " << env.index << " Spalte 3:\n" << env.array[env.index][2] << "\n";
                        env.index++;
                    } 
                    else if (entry["type"].asString() == "EXE") {
                        exe.type = entry["type"].asString();
                        exe.command = entry["command"].asString();
                        exe.array[exe.index][0] = exe.type;
                        exe.array[exe.index][1] = exe.command;
                        std::cout << "exe Ausgabe: \nZeile: " << exe.index << " Spalte 1:\n" << exe.array[exe.index][0] << "\n";
                        std::cout << "Zeile: " << exe.index << " Spalte 2:\n" << exe.array[exe.index][1] << "\n";
                        exe.index++;
                    } 
                    else if (entry["type"].asString() == "PATH") {
                        path.type = entry["type"].asString();
                        path.path = entry["path"].asString();
                        path.array[path.index][0] = path.type;
                        path.array[path.index][1] = path.path;
                        std::cout << "path Ausgabe: \nZeile: " << path.index << " Spalte 1:\n" << path.array[path.index][0] << "\n";
                        std::cout << "Zeile: " << path.index << " Spalte 2:\n" << path.array[path.index][1] << "\n";
                        path.index++;
                    }     
                }
                std::cout << env.array[1][0] << "\n";
                std::cout << env.array[1][1] << "\n";
                std::cout << env.array[1][2] << "\n";
            }
            else {
                std::cout << "Fehler beim Lesen von outputfile" << std::endl;
            }
            // Schließen der Datei nach Abschluss

            file.close();
        } 
        else {
            std::cout << "File " << argv << " does not exist or the path is wrong" << "\n";
        }
    }
}

// Function to determine if the user inputs ends in json 
bool JsonReader::endsWithJson(std::string fileName, std::string targetEnding) {
    // Compare if the user input file has less letters then the target: ".json"
    if (targetEnding.size() > fileName.size()) {
        std::cout << "Filename: " << fileName << " does not end in .json" << "\n";
        // Return false if so
        return false;
    }
    // Comparing both strings and return true if they are equal to 0 (they compare equal)
    return fileName.compare(fileName.size() - targetEnding.size(), targetEnding.size(), targetEnding) == 0;
}

bool JsonReader::check_types(std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Fehler: Die JSON Datei kann nicht geöffnet werden" << std::endl;
        return false;
    }

    std::string line;
    int lineNumber = 0;

    // Read the JSON file line by line
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
