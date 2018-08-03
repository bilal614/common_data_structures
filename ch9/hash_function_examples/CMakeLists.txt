cmake_minimum_required (VERSION 2.8)


# This is the name of the project
PROJECT(hash_funcs C CXX)

#To generate debugging information to use with gdb
set(CMAKE_BUILD_TYPE Debug)

#Bring the headers, such as Student.h into the project
INCLUDE_DIRECTORIES(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cxx")

ADD_EXECUTABLE(hash_funcs_main  ${SOURCES})
