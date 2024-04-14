cmake_minimum_required(VERSION 3.10)
project(ProgrammierProjekt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fügen Sie hier alle Quelldateien hinzu
add_executable(MeineAnwendung main.cpp)

#Bin nicht sicher ob wir das brauchen
# include(FetchContent)
# FetchContent_Declare(
#     fmt
#     GIT_REPOSITORY https://github.com/Fybii/Projekt_Haarglatzfall.git
#     GIT_TAG #Hab keins gefunden schau noch warum wir es genauer brauchen
# )

# FetchContent_MakeAvailable(fmt)

add_executable(main.cpp)

# Konfigurieren Sie hier zusätzliche Einstellungen, z. B. Compiler-Flags oder Bibliotheken
