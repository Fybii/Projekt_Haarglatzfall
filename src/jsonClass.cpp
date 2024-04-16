#include <iostream>

class Entry {
    public:
        std::string type;
        int index = 0;
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
