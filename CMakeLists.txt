cmake_minimum_required(VERSION 3.10)
project(ProgrammierProjekt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Alle Cpp dateien die wir brauchen:
set(SOURCES src/main.cpp src/jsonClass.cpp)

# Fügen Sie hier alle Quelldateien hinzu
add_executable(ProgrammierProjekt ${SOURCES})

target_include_directories(ProgrammierProjekt PRIVATE ${PROJECT_SOURCE_DIR}/header)
target_link_libraries(ProgrammierProjekt jsoncpp)
# Konfigurieren Sie hier zusätzliche Einstellungen, z. B. Compiler-Flags oder Bibliotheken
