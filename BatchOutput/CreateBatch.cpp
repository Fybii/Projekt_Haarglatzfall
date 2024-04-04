// C++ implementation to create a file
 
#include <jsoncpp/json/json.h>
#include <fstream>  
#include <bits/stdc++.h> 


// Driver code 
int main() 
{ 
    // Open the JSON file
    std::ifstream batchFile("../Test.json", std::ifstream::binary);

    // Parse the JSON file into a Json::Value object
    Json::Value root;
    batchFile >> root;

    // Close the file
    batchFile.close();

    // Check if the JSON parsing was successful
    if (batchFile.fail())
    {
        std::cerr << "Error reading JSON file." << std::endl;
        return 1;
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
            Json::Value outputFileValue = firstElement["outputfile"];

            // Check if the key "outputfile" exists in the JSON
            if (!outputFileValue.isNull())
            {
                // Print the value of "outputfile"
                std::cout << "Value of outputfile: " << outputFileValue.asString() << std::endl;
            }
            else
            {
                std::cerr << "Key 'outputfile' not found in JSON." << std::endl;
            }
        }
        else
        {
            std::cerr << "The first element is not an object." << std::endl;
        }
    }
    else
    {
        std::cerr << "Root is not an array or is empty." << std::endl;
    }


    // fstream is Stream class to both 
    // read and write from/to files. 
    // file is object of fstream class 
   std::fstream file; 
  
   // opening file "Gfg.txt" 
   // in out(write) mode 
   // ios::out Open for output operations. 
   file.open("mybatchfile.bat",std::ios::out); 
  
   // If no file is created, then 
   // show the error message. 
   if(!file) 
   { 
       std::cout<<"Error in creating file!!!"; 
       return 0; 
   } 
  
   std::cout<<"File created successfully. "; 

    // Create a batch file named "mybatchfile.bat"
    system("echo @echo OFF > mybatchfile.bat");
    system("echo :START >> mybatchfile.bat");
    system("echo dir C:\\ >> mybatchfile.bat");
    system("echo CreateBatch.exe>nul >> mybatchfile.bat");
    system("echo goto :eof >> mybatchfile.bat");

    // Execute the batch file
//    system("mybatchfile.bat");

    std::cout << "Starting Batch File... " << std::endl;
    return 0;
  
   // closing the file. 
   // The reason you need to call close() 
   // at the end of the loop is that trying 
   // to open a new file without closing the 
   // first file will fail. 
   file.close(); 
  
   return 0; 
}
