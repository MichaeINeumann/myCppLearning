cmake_minimum_required(VERSION 3.10)

# Projektname und Version
project(simpleCalculator VERSION 1.0)

# Setze den Standard-C++-Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Füge die ausführbare Datei hinzu
add_executable(simpleCalculator 
    main.cpp 
    Rechner.cpp)

add_executable(runTests 
    tests/catch_amalgamated.cpp
    tests/tests.cpp
    Rechner.cpp)

target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR}/tests)

# Erzwinge das Konsolen-Subsystem unter Windows
if (WIN32)
    set_target_properties(simpleCalculator PROPERTIES LINK_FLAGS "-Wl,-subsystem,console")
    set_target_properties(runTests PROPERTIES LINK_FLAGS "-Wl,-subsystem,console")
    message(STATUS "Windows detected, setting console subsystem for executables.")
endif()
