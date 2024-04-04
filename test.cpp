#include <iostream>
#include <unistd.h>
#include <string>

int main(int argc, char *argv[]) {
    int opt;
    bool helpRequested = false;

    // Optionen definieren
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                // Überprüfen, ob es sich genau um "-h" oder "--help" handelt
                if (optarg == nullptr || (std::string(optarg) == "h" && optind == 2)) {
                    helpRequested = true;
                } else {
                    std::cerr << "Unbekannte Option: -" << optarg << std::endl;
                    return 1;
                }
                break;
            default:
                std::cerr << "Unbekannte Option: " << static_cast<char>(optopt) << std::endl;
                return 1;
        }
    }

    // Überprüfen, ob Hilfe angefordert wurde
    if (helpRequested) {
        std::cout << "Hilfetext hier..." << std::endl;
        return 0;
    }

    // Hier können Sie den Rest Ihres Programms ausführen

    return 0;
}