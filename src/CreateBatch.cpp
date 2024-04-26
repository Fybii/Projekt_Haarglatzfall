#include "jsonFinder.h"
#include "jsonClass.h"
#include <fstream>
#include <iostream>

void createBatchFile(JsonReader file)
{
    // Öffnen Sie die Batch-Datei mit dem Namen von outputFileValue
    std::string name = file.outputfileValue.asString();
    int nameLength = name.length();
    std::string fileName;

    for (int i = 0; i < nameLength; i++) {
        if (name[i] == '.') {
            std::string beforePoint = name.substr(0, i);
            fileName = beforePoint + ".bat";
            std::ofstream batchFile(fileName, std::ios::binary);
            break;
        }
        else if ( i == nameLength - 1){
            fileName = name + ".bat";
            std::ofstream batchFile(filename, std::ios::binary);
        }
    }

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
                if(!command.empty() && !file.exe.array[i + 1][1].empty()) {
                    batchFile << command << " && ";
                }
                else {
                    if (!file.env.array[0][0].empty()) {
                        batchFile << command << " && ";
                    }
                    else {
                        batchFile << command;
                    }
                }
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
                if (!key.empty() && !file.env.array[i + 1][1].empty() && !file.path.array[0][0].empty()) {
                    batchFile << "set " << key << "=" << value << " && ";
                }
                else 
                {
                    if (!file.path.array[0][0].empty()) {
                        batchFile << "set " << key << "=" << value << " && ";
                    }
                    else {
                        batchFile << "set " << key << "=" << value;
                    }
                }
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
            if (i == 0)
            {
                batchFile << "set path=;" << path << ";";
            }
            else
            {
                std::string path = file.path.array[i][1];
                if (!path.empty() && !file.path.array[i + 1][1].empty())
                {
                    batchFile <<  path << ";";
                }
                else
                {
                    batchFile << path << ";%path%";
                }
            }
        }
    }

    if (!file.applicationValue.isNull())
    {
        batchFile << " && start \"" + filename + "\" " << file.applicationValue.asString();
    }

    batchFile << "\"\n@ECHO ON\r\n";
    // Batch-Datei schließen
    batchFile.close();

    std::cout << "Batch-Datei erfolgreich erstellt." << std::endl;

    file.exe.clearArray(file.exe.array, exeSize);
    file.env.clearArray(file.env.array, envSize);
    file.path.clearArray(file.path.array, pathSize);

}

/*
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
*/
/*
ChatGPT
Der Code hat einige Fehler und Unklarheiten, aber ich kann Ihnen helfen, diese zu korrigieren:

Es gibt einen Syntaxfehler in der Zeile, die pointPosition zuweist. Es sollte name.find('.') sein, nicht name.find{"."}.
Sie haben beforePoint nicht deklariert, bevor Sie versuchen, ihm einen Wert zuzuweisen. Sie müssen es als std::string deklarieren, bevor Sie es verwenden.
Die Variable batchFile ist nur innerhalb der Schleife sichtbar, aber Sie verwenden sie außerhalb der Schleife. Sie sollten sicherstellen, dass batchFile im gesamten Gültigkeitsbereich verwendet werden kann.
Die Variable fileName wird deklariert, aber nicht verwendet. Wenn Sie den Dateinamen verwenden möchten, stellen Sie sicher, dass Sie ihn irgendwo verwenden.
Es gibt einige logische Probleme bei der Verwendung von beforePoint. Es scheint, dass Sie versuchen, den Dateinamen ohne Erweiterung zu bekommen. Wenn dies der Fall ist, sollten Sie den Code entsprechend anpassen.
Hier ist der überarbeitete Code:

cpp
Copy code
std::string name = file.outputfileValue.asString();
int periodCount = 0;
int nameLength = name.length();
std::string fileName;

for (int i = 0; i < nameLength; i++) {
    if (name[i] == '.') {
        size_t pointPosition = name.find('.');
        std::string beforePoint = name.substr(0, pointPosition);
        std::ofstream batchFile(beforePoint + ".bat", std::ios::binary);
        fileName = beforePoint + ".bat";
        break;
    }
    else if (i == nameLength - 1) {
        std::ofstream batchFile(name + ".bat", std::ios::binary);
        fileName = name + ".bat";
    }
    else {
        periodCount++;
    }
}

// Überprüfen, ob die Datei erfolgreich geöffnet wurde
if (!batchFile.is_open())
{
    std::cerr << "Fehler beim Erstellen der Batch-Datei!" << std::endl;
    return;
}
*/