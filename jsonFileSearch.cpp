#include <iostream>
#include <fstream>
#include <string.h>
#include <dirent.h>

void listFiles(const char* dirname) {
    DIR* dir = opendir(".");
    if(dir == NULL) {
        return;
    }
    std::cout << "Reading files in: " << dirname << "\n";
    struct dirent* entity;
    entity = readdir(dir);
    while(entity != NULL) {
        std::cout << entity -> d_type << entity -> d_name << "\n";
        if(entity -> d_type == DT_DIR && strcmp(entity -> d_name, ".") != 0 && strcmp(entity -> d_name, "..") != 0) {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity -> d_name);
            listFiles(path);

        }
        entity = readdir(dir);
    }
    closedir(dir);
}

int main(int argc, char const *argv[])
{
    if(argc < 1) {
        std::cout << "Need an File name";
    }
    else {
        listFiles(".");
        std::ifstream in(argv[2]);
        if(in.is_open()) {

            std::string line;
            while(std::getline(in, line)) {
                if(line.find("outputfile") != std::string::npos) {
                    if(line.find("Name") != std::string::npos) {
                        std::cout << "Found\n";
                    }
                }
                std::cout << line << "\n";
            }
            in.close();
        }
        else {
            std::cout << "File didn't exist\n";
        }

    }
    return 0;
    
}

