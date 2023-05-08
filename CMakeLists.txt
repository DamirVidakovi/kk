# set the project name
project(kk)

# set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.8)


# add the source files to the project form the src directory
file(GLOB SOURCES "src/*.c")

# add the header files to the project from the headers directory
file(GLOB HEADERS "headers/*.h")

# add the include directory to the project
include_directories(headers)

# add the executable to the project
add_executable(kk ${SOURCES} ${HEADERS})



