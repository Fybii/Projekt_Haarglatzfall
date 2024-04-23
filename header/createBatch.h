#ifndef CREATEBATCH
#define CREATEBATCH

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include "createBatch.h"
#include "jsonClass.h"
#include "jsonFinder.h"

// Function to create and write to the batch file
void createBatchFile(JsonReader file) 
{
    // Open the batch file with the name from outputFileValue
    std::ofstream batchFile(file.outputfileValue.asString() + ".bat", std::ios::binary);  // Öffnen im Binärmodus
    
    // Check if the file is opened successfully
    if (!batchFile.is_open())
    {
        std::cerr << "Error in creating batch file!" << std::endl;
        return;
    }

    // Write commands to the batch file

if (file.hideshellValue == true)
    {
        batchFile << "echo off\r\n";
        batchFile << "cmd.exe /c exit\r\n";  // Add the exit command to close the Command Prompt window
    }
    else
    {
        batchFile << "echo on\r\n";          // Re-enable command echoing
        batchFile << "cmd.exe /k\r\n";        // Keep the Command Prompt window open
    }


    int exeSize = sizeof(file.exe.array) / sizeof(file.exe.array[0]);
    // Prozess entries
    for (int i = 0; i < exeSize; i++) {
        if (!file.exe.array[i][0].empty())
        {
            std::string command = file.exe.array[i][1];
            if (!command.empty()) {
                batchFile << command << " && ";
            }
        }
    }
    int envSize = sizeof(file.env.array)/sizeof(file.env.array[0]);
    // Prozess entries
    for (int i = 0; i < envSize; i++) {
        if (!file.env.array[i][0].empty())
        {
            std::string key = file.env.array[i][1];
            std::string value = file.env.array[i][2];
            if (!key.empty() && !value.empty()) {
            batchFile << "set " << key << "=" << value << " && ";
            }
        }
    }
    int pathSize = sizeof(file.path.array)/sizeof(file.path.array[0]);
    // Prozess entries
    for (int i = 0; i < pathSize; i++) {
        if (!file.path.array[i][0].empty())
        {
            std::string path = file.path.array[i][1];
            if (!path.empty() && !file.path.array[i+1][1].empty()) {
                batchFile << "set PATH=%PATH%;" << path << " && ";
            }
            else {
                batchFile << "set PATH=%PATH%;" << path;
            }
        }
    }
        
        /*
        for (const auto& entry : file.entries)
        {
            std::string type = entry["type"].asString();
            
            if (type == "ENV")
            {
                std::string key = entry["key"].asString();
                std::string value = entry["value"].asString();
                
                batchFile << "set " << key << "=" << value << " && ";
            }
            else if (type == "EXE")
            {
                std::string command = entry["command"].asString();
                
                batchFile << command << " && ";
            }
            else if (type == "PATH")
            {
                std::string path = entry["path"].asString();
                batchFile << "set PATH=%PATH%;" << path << " && ";
            }
        }
        */

    // Check if hideShell is true
    

    if (!file.applicationValue.isNull() && !file.applicationValue.asString().empty())
{
    batchFile << file.applicationValue.asString() << std::endl;
}

    // Close the batch file
    batchFile.close();

    std::cout << "Batch file created successfully." << std::endl;

    // Check the operating system and execute the batch file
    #ifdef _WIN32
        std::string command = "start " + file.outputfileValue.asString() + ".bat";
        system(command.c_str());
    #elif __linux__ || __APPLE__
        std::string command = "chmod +x \"" + file.outputfileValue.asString() + ".bat\" && ./\"";
        command += file.outputfileValue.asString() + ".bat\"";
        system(command.c_str());
    #endif
}

void mainA(JsonReader file) 
{ 
    // Open the JSON file
    std::ifstream batchFile("../Test2.json", std::ifstream::binary);

    // Parse the JSON file into a Json::Value object
    Json::Value root;
    batchFile >> root;

    // Close the file
    batchFile.close();

    // Check if the JSON parsing was successful
    if (batchFile.fail())
    {
        std::cerr << "Error reading JSON file." << std::endl;
        //return 1;
    }

    // Check if the root is an array and has at least one element
    if (root.isArray() && !root.empty())
    {
        // Access the first element of the array
        Json::Value firstElement = root[0];

        // Check if the first element is an object
        if (firstElement.isObject())
        {
         // Access the value with the key "outputfile"
        file.outputfileValue = firstElement["outputfile"];

            // Access the value with the key "hideshell"
            file.hideshellValue = firstElement.get("hideshell", false).asBool();


            // Check if the key "outputfile" exists in the JSON
            if (!file.outputfileValue.isNull())
            {
                // Print the value of "outputfile"
                std::cout << "Value of outputfile: " << file.outputfileValue.asString() << std::endl;

                // Create and write to the batch file
                createBatchFile(file);
            }
            else
            {
                std::cerr << "Key 'outputfile' not found in JSON." << std::endl;
                //return 1;  // Return if key not found
            }
        }
        else
        {
            std::cerr << "The first element is not an object." << std::endl;
            //return 1;  // Return if not an object
        }
    }
    else
    {
        std::cerr << "Root is not an array or is empty." << std::endl;
        //return 1;  // Return if root is not an array or is empty
    }

   //return 0;
}


#endif