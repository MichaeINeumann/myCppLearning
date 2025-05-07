cmake_minimum_required(VERSION 3.10)

# Projektname und Version
project(simpleCalculator VERSION 1.0)

# Setze den Standard-C++-Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

set(SKIP_TESTS ON)
set(SKIP_BENCHMARKS ON)
set(SKIP_EXAMPLES ON)

FetchContent_Declare(
    graaflib
    GIT_REPOSITORY https://github.com/bobluppes/graaf.git
    GIT_TAG main
)
FetchContent_MakeAvailable(graaflib)


# Füge die ausführbare Datei hinzu
add_executable(simpleCalculator 
    main.cpp 
    Rechner.cpp
    VectorCalc.cpp)

add_executable(runTests 
    tests/catch_amalgamated.cpp
    tests/tests.cpp
    tests/test_graphtool.cpp
    Rechner.cpp
    VectorCalc.cpp)

target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR}/tests)


target_link_libraries(${PROJECT_NAME} PRIVATE Graaf::Graaf)
target_link_libraries(runTests PRIVATE Graaf::Graaf)

add_library(GraphTool GraphTool.cpp)
target_include_directories(GraphTool PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(GraphTool PUBLIC Graaf::Graaf)

target_link_libraries(runTests PRIVATE GraphTool)


# Erzwinge das Konsolen-Subsystem unter Windows
if (WIN32)
    set_target_properties(simpleCalculator PROPERTIES LINK_FLAGS "-Wl,-subsystem,console")
    set_target_properties(runTests PROPERTIES LINK_FLAGS "-Wl,-subsystem,console")
    message(STATUS "Windows detected, setting console subsystem for executables.")
endif()
