cmake_minimum_required(VERSION 3.10)
project(JsonToBatch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Alle Cpp dateien die wir brauchen:
set(SOURCES src/main.cpp src/jsonClass.cpp src/jsonFinder.cpp src/command.cpp src/CreateBatch.cpp)

# Fügen Sie hier alle Quelldateien hinzu
add_executable(JsonToBatch ${SOURCES})

target_include_directories(JsonToBatch PRIVATE ${PROJECT_SOURCE_DIR}/header)
target_link_libraries(JsonToBatch jsoncpp)
# Konfigurieren Sie hier zusätzliche Einstellungen, z. B. Compiler-Flags oder Bibliotheken
