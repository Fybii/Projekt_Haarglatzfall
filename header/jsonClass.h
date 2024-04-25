#ifndef JSON_CLASS
#define JSON_CLASS  

#include <iostream>

class Entry {
    public:
        std::string type;
        int index = 0;

        void clearArray(std::string array[][2], int arraySize) {
            for (int i = 0; i < arraySize; i++) {
                for (int j = 0; j < 2; j++) {
                    array[i][j] = "";
                }
            }
        }

        void clearArray(std::string array[][3], int arraySize) {
            for (int i = 0; i < arraySize; i++) {
                for (int j = 0; j < 3; j++) {
                    array[i][j] = "";
                }
            }
        }
};

class ENV : public Entry {
    public:
        std::string key;
        std::string value;
        std::string array[100][3];
};

class EXE : public Entry {
    public:
        std::string command;
        std::string array[100][2];
};

class PATH : public Entry {
    public:
        std::string path;
        std::string array[100][2];
};

#endif