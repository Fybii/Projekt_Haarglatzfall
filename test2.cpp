#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void sucheDatei(const std::string& dateiname) {
    for (const auto& eintrag : fs::recursive_directory_iterator("/")) { // Hier wird "/" als Wurzelverzeichnis angegeben
        if (eintrag.is_regular_file() && eintrag.path().filename() == dateiname) {
            std::cout << "Gefundene Datei: " << eintrag.path() << std::endl;
            return;
        }
    }
    std::cerr << "Die Datei \"" << dateiname << "\" wurde nicht gefunden." << std::endl;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Verwendung: " << argv[0] << " dateiname.json" << std::endl;
        return 1;
    }

    std::string dateiname = argv[1];
    sucheDatei(dateiname);

    return 0;
}

