#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>

class Reader {
public:
    std::string outputfile; // Variable zum Speichern des Wertes von "outputfile"
    bool hideshell; // Variable zum Speichern des Wertes von "hideshell"
    std::string application; // Variable zum Speichern des Pfads und Namens der auszuführenden Anwendung

    // Funktion zum Lesen einer JSON-Datei
    void readJSON(char const *argv) {
        // Öffnen der Datei aus der Benutzereingabe
        std::ifstream in(argv);
        // Überprüfen, ob die Datei geöffnet wurde
        if (in.is_open()) {
            std::string line;
            // Schleife zum Lesen jeder Zeile in der JSON-Datei
            while (std::getline(in, line)) {
                // Suchen nach dem Schlüssel "outputfile"
                size_t pos = line.find("\"outputfile\":");
                if (pos != std::string::npos) {
                    // Wenn der Schlüssel gefunden wurde, extrahieren Sie den Wert von "outputfile"
                    size_t start = line.find_first_of('"', pos + 1);
                    size_t end = line.find_first_of('"', start + 1);
                    outputfile = line.substr(start + 1, end - start - 1);
                }

                // Suchen nach dem Schlüssel "hideshell"
                pos = line.find("\"hideshell\":");
                if (pos != std::string::npos) {
                    // Wenn der Schlüssel gefunden wurde, extrahieren Sie den Wert von "hideshell"
                    size_t start = line.find_first_of(':', pos + 1);
                    size_t end = line.find_first_of(',', start + 1);
                    std::string value = line.substr(start + 1, end - start - 1);

                    // Interpretieren Sie den Wert von "hideshell" als booleschen Wert
                    hideshell = (value == "true") ? true : false;
                }

                // Suchen nach dem Schlüssel "application"
                pos = line.find("\"application\":");
                if (pos != std::string::npos) {
                    // Wenn der Schlüssel gefunden wurde, extrahieren Sie den Wert von "application"
                    size_t start = line.find_first_of('"', pos + 1);
                    size_t end = line.find_first_of('"', start + 1);
                    application = line.substr(start + 1, end - start - 1);
                }
            }
            // Schließen der Datei nach Abschluss
            in.close();
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
