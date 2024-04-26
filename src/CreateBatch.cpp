#include "jsonFinder.h"
#include "jsonClass.h"
#include <fstream>
#include <iostream>

// Function to create a batch file
void createBatchFile(JsonReader file)
{
    // Get the output file name from the JSON object, which is saved in an array
    std::string name = file.outputfileValue.asString();
    //// Calculate the length of the file name
    int nameLength = name.length();
    std::string fileName;

    //Ensure that the name of every batch file has no ".", apart from ".bat" at the end
    //search all characters for "."
    for (int i = 0; i < nameLength; i++) {
        // If "." is found cut the string in two and only take the first part
        if (name[i] == '.') {
            std::string beforePoint = name.substr(0, i);
            //append the ending ".bat" to the first part of the original string
            fileName = beforePoint + ".bat";
            break;
        }
        // If there is no "." in the string, append a ".bat" at the end
        else if ( i == nameLength - 1){
            fileName = name + ".bat";
        }
    }
    //Name the file according to the value of filename
    std::ofstream batchFile(fileName, std::ios::binary);


    // Check if the file was opened successfully
    if (!batchFile.is_open())
    {
        std::cerr << "Fehler beim Erstellen der Batch-Datei!" << std::endl;
        return;
    }

    // First command of the batch file
    batchFile << "@ECHO OFF\n";

    //If hideshell is true, then close the console after the appliction in
    //the batchfile has been completed
    if (file.hideshellValue == true)
    {
        batchFile << "C:\\Windows\\System32\\cmd.exe /c \""; 
    }
    // otherwise, keep the console open
    else
    {
        batchFile << "C:\\Windows\\System32\\cmd.exe /k \"";
    }
    // Loop through the exe array and write the following in the batch file
    int exeSize = sizeof(file.exe.array) / sizeof(file.exe.array[0]);
    for (int i = 0; i < exeSize; i++)
    {
        //check if there is a "EXE"
        if (!file.exe.array[i][0].empty())
        {
            std::string command = file.exe.array[i][1];
            //check if the command is empty
            if (!command.empty())
            {
                //print each command into the batch and connect them with " && "
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
    // Loop through the env array and write the following in the batch file
    int envSize = sizeof(file.env.array) / sizeof(file.env.array[0]);
    for (int i = 0; i < envSize; i++)
    {
        //check if there is a "ENV"
        if (!file.env.array[i][0].empty())
        {
            std::string key = file.env.array[i][1];
            std::string value = file.env.array[i][2];
            //check if the key and value is empty
            if (!key.empty() && !value.empty())
            {
                //print each key and value into the batch, set key=value and connect them with " && "
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
    // Loop through the path array and write the following in the batch file
    int pathSize = sizeof(file.path.array) / sizeof(file.path.array[0]);
    for (int i = 0; i < pathSize; i++)
    {
        //check if there is a "PATH"
        if (!file.path.array[i][0].empty())
        {
            std::string path = file.path.array[i][1];
            //before printing the first path print "set path="
            if (i == 0)
            {
                batchFile << "set path=" << path << ";";
            }
            //connect each path with a ";"
            else
            {
                std::string path = file.path.array[i][1];
                if (!path.empty() && !file.path.array[i + 1][1].empty())
                {
                    batchFile <<  path << ";";
                }
                //write ";%path%" after the last path
                else
                {
                    batchFile << path << ";%path%";
                }
            }
        }
    }

    // If an application value is provided, write it to the batch file
    if (!file.applicationValue.isNull())
    {
        batchFile << " && start \"" + fileName + "\" " << file.applicationValue.asString();
    }

    batchFile << "\"\n@ECHO ON\r\n";
    // Close the batch file when done
    batchFile.close();

    std::cout << "Batch-Datei erfolgreich erstellt." << std::endl;

    // Clear the arrays to free memory
    file.exe.clearArray(file.exe.array, exeSize);
    file.env.clearArray(file.env.array, envSize);
    file.path.clearArray(file.path.array, pathSize);

}
