cmake_minimum_required(VERSION 3.15)
project(expSolver)

# cpp file position
aux_source_directory(${PROJECT_SOURCE_DIR}/controller CONTROLLER) # search cpp file
aux_source_directory(${PROJECT_SOURCE_DIR}/services SERVICE)
file(GLOB ENTRY ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# compile option
set(CMAKE_CXX_STANDARD 11) # cpp version
set(EXECUTABLE_OUTPUT_PATH ../target) # output path
include_directories(${PROJECT_SOURCE_DIR}/includes)


add_executable(app ${ENTRY} ${CONTROLLER} ${SERVICE})

