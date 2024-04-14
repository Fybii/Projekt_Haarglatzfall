#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    Json::Value root;
    Json::Reader reader;

    std::ifstream file("Test2.json");    
    file >> root;

    std::cout << root << std::endl;
    
    // Greife auf den Wert von "outputfile" zu
    const Json::Value outputfileValue = root[0]["outputfile"];

    const Json::Value arschfickValue = root[0]["arschfick"];

    // Überprüfe, ob der Wert korrekt ausgelesen wurde
    if (!outputfileValue.isNull())
    {
        std::cout << "Der Wert von outputfile ist: " << outputfileValue.asString() << std::endl;
        std::cout << "Der Wert von arschfick ist: " << arschfickValue.asString() << std::endl;
    }
    else
    {
        std::cout << "Fehler beim Lesen von outputfile" << std::endl;
    }

    return 0;
}
