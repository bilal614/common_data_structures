cmake_minimum_required (VERSION 2.8)


# This is the name of the project
PROJECT(n_tree_data_structure C CXX)

#Bring the headers, such as Student.h into the project
INCLUDE_DIRECTORIES(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cxx")


ADD_EXECUTABLE(tree_main  ${SOURCES})
