#include "createBatch.h"
#include "jsonFinder.h"
#include "jsonClass.h"
#include <fstream>
#include <iostream>

void createBatchFile(JsonReader file)
{
    // Öffnen Sie die Batch-Datei mit dem Namen von outputFileValue
    std::ofstream batchFile(file.outputfileValue.asString() + ".bat", std::ios::binary);

    // Überprüfen, ob die Datei erfolgreich geöffnet wurde
    if (!batchFile.is_open())
    {
        std::cerr << "Fehler beim Erstellen der Batch-Datei!" << std::endl;
        return;
    }

    // Befehle in die Batch-Datei schreiben
    batchFile << "@ECHO OFF\n";

    if (file.hideshellValue == true)
    {
        batchFile << "C:\\Windows\\System32\\cmd.exe /c \""; // Befehlsfenster schließen
    }
    else
    {
        batchFile << "C:\\Windows\\System32\\cmd.exe /k \""; // Befehlsfenster offen lassen
    }

    int exeSize = sizeof(file.exe.array) / sizeof(file.exe.array[0]);
    // Prozesseinträge
    for (int i = 0; i < exeSize; i++)
    {
        if (!file.exe.array[i][0].empty())
        {
            std::string command = file.exe.array[i][1];
            if (!command.empty())
            {
                batchFile << command << " && ";
            }
        }
    }
    int envSize = sizeof(file.env.array) / sizeof(file.env.array[0]);
    // Umgebungsvariablen Einträge
    for (int i = 0; i < envSize; i++)
    {
        if (!file.env.array[i][0].empty())
        {
            std::string key = file.env.array[i][1];
            std::string value = file.env.array[i][2];
            if (!key.empty() && !value.empty())
            {
                batchFile << "set " << key << "=" << value << " && ";
            }
        }
    }
    int pathSize = sizeof(file.path.array) / sizeof(file.path.array[0]);
    // Pfad Einträge
    for (int i = 0; i < pathSize; i++)
    {
        if (!file.path.array[i][0].empty())
        {
            std::string path = file.path.array[i][1];
            if (!path.empty() && !file.path.array[i + 1][1].empty())
            {
                batchFile << "set PATH=%PATH%;" << path << " && ";
            }
            else
            {
                batchFile << "set PATH=%PATH%;" << path;
            }
        }
    }

    if (!file.applicationValue.isNull() && !file.applicationValue.asString().empty())
    {
        batchFile << file.applicationValue.asString() << std::endl;
    }

    batchFile << "\"\n@ECHO ON\r";
    // Batch-Datei schließen
    batchFile.close();

    std::cout << "Batch-Datei erfolgreich erstellt." << std::endl;
}

void mainA(JsonReader file)
{
    std::ifstream batchFile("../Test2.json", std::ifstream::binary);

    // JSON-Datei in ein Json::Value-Objekt parsen
    Json::Value root;
    batchFile >> root;

    // Datei schließen
    batchFile.close();

    if (batchFile.fail())
    {
        std::cerr << "Fehler beim Lesen der JSON-Datei." << std::endl;
    }

    if (root.isArray() && !root.empty())
    {
        Json::Value firstElement = root[0];

        if (firstElement.isObject())
        {
            file.outputfileValue = firstElement["outputfile"];
            file.hideshellValue = firstElement.get("hideshell", false).asBool();

            if (!file.outputfileValue.isNull())
            {
                std::cout << "Wert von outputfile: " << file.outputfileValue.asString() << std::endl;
                createBatchFile(file);
            }
            else
            {
                std::cerr << "Schlüssel 'outputfile' nicht gefunden im JSON." << std::endl;
            }
        }
        else
        {
            std::cerr << "Das erste Element ist kein Objekt." << std::endl;
        }
    }
    else
    {
        std::cerr << "Root ist kein Array oder ist leer." << std::endl;
    }
}
