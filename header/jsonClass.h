// ReqNonFunc 8
#ifndef JSON_CLASS_H
#define JSON_CLASS_H

#include <iostream>

// Req Func 14

class Entry {
public:
    std::string type;
    int index = 0;

    void clearArray(std::string array[][2], int arraySize);
    void clearArray(std::string array[][3], int arraySize);
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
