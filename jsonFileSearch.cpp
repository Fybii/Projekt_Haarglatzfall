#include <iostream>
#include <fstream>

void readJSON(char const *position[]) {
    int i = 1;
    std::string fileName = position[i];
    if(position[i] == "") {
        return;
    }
    else {
        std::ifstream in(position[i]);
        if (in.is_open()) {
            std::string line;
            while(std::getline(in, line)) {
                std::cout << line << "\n";
            }
        in.close();
        readJSON(&position[i+1]);
        }
        else {
            std::cout << "File " << fileName << " didn't exist" << "\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    if(argc < 1) {
        std::cout << "Need an File name";
    }
    else {

        readJSON(&argv[1]);
        std::cout << argv[2] << "\n";
    }
    return 0;
    
}

