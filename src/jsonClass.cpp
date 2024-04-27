#include "jsonClass.h"

// Clear array function
void Entry::clearArray(std::string array[][2], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < 2; j++) {
            array[i][j] = "";
        }
    }
}

// Clear array function
void Entry::clearArray(std::string array[][3], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = "";
        }
    }
}
