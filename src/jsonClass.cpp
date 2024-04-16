#include <iostream>


class Entry {
    public:
        std::string type;
        int index = 0;

        std::string pushValueInArray(ENV env, int index){
            env.array[index][0] = env.type;
            env.array[index][1] = env.key;
            env.array[index][2] = env.value;
            return env.array[index][3];
    }

        std::string pushValueInArray(EXE exe, int index) {
            exe.array[index][0] = exe.type;
            exe.array[index][1] = exe.command;
            return exe.array[index][2];
    }

        std::string pushValueInArray(PATH path, int index) {
            path.array[index][0] = path.type;
            path.array[index][1] = path.path;
            return path.array[index][2];
        }
};

class ENV : public Entry {
    public:
        std::string key;
        std::string value;
        std::string array[][3];
};

class EXE : public Entry {
    public:
        std::string command;
        std::string array[][2];
};

class PATH : public Entry {
    public:
        std::string path;
        std::string array[][2];
};
