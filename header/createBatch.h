#ifndef CREATEBATCH
#define CREATEBATCH

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include "createBatch.h"
#include "jsonClass.h"
#include "jsonFinder.h"


// Declare outputFileValue as a global variable

//Momontarily set as false (can change)
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
    batchFile << "@echo off" << std::endl;

    // Check if hideShell is true
    if (file.hideshellValue)
    {
        batchFile << "cmd.exe /c exit\r\n";  // Add the exit command to close the Command Prompt window
    }
    else
    {
        batchFile << "cmd.exe /k\r\n";        // Keep the Command Prompt window open
        batchFile << "@echo on\r\n";          // Re-enable command echoing
    }

    // Close the batch file
    batchFile.close();

    std::cout << "Batch file created successfully." << std::endl;

    // Check the operating system and execute the batch file
    #ifdef _WIN32
        std::string command = "start " + outputFileValue.asString() + ".bat";
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