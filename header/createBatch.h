#ifndef CREATEBATCH
#define CREATEBATCH

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include "createBatch.h"
#include "jsonClass.h"
#include "jsonFinder.h"

// Function to create a batch file
void createBatchFile(JsonReader file) 
{
    // Open a new batch file with the outputfilename from the Json
    std::ofstream batchFile(file.outputfileValue.asString() + ".bat", std::ios::binary);  
    
    // Check if the file is successfully opened
    if (!batchFile.is_open())
    {
        std::cerr << "Error in creating batch file!" << std::endl;
        return;
    }
    // initial batch file command
    batchFile << "@ECHO OFF\n";

    // Check if the shell should be hidden
    if (file.hideshellValue == true)
        {
            batchFile << "C:\\Windows\\System32\\cmd.exe /c \"";  // 
        }
        else
        {
            batchFile << "C:\\Windows\\System32\\cmd.exe /k \"";        
        }

    //calculate the number of elements in the exe-array 
    int exeSize = sizeof(file.exe.array) / sizeof(file.exe.array[0]);
    //Print each command in the array into the batchfile and seperate them with && 
    for (int i = 0; i < exeSize; i++) {
        if (!file.exe.array[i][0].empty())
        {
            std::string command = file.exe.array[i][1];
            if (!command.empty()) {
                batchFile << command << " && ";
            }
        }
    }
    //calculate the number of elements in the env-array 
    int envSize = sizeof(file.env.array)/sizeof(file.env.array[0]);
    //Set each key in the array to its corresponding value and print it 
    //into the batchfile and seperate them with && 
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
    //calculate the number of elements in the path-array 
    int pathSize = sizeof(file.path.array)/sizeof(file.path.array[0]);
    //Set the Path and Print it into the batchfile. Use && if its not the last entry
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


    
    //If there is an applicationValue then print it
    if (!file.applicationValue.isNull() && !file.applicationValue.asString().empty())
    {
    batchFile << file.applicationValue.asString() << std::endl;
    }
    //Last batch command
    batchFile << "\"\n@ECHO ON\r";
    batchFile.close();

    std::cout << "Batch file created successfully." << std::endl;
}

#endif