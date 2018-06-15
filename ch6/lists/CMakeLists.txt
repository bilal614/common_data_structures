cmake_minimum_required (VERSION 2.8)


# This is the name of the project
PROJECT(data_structure_iterators C CXX)

#Bring the headers, such as Student.h into the project
INCLUDE_DIRECTORIES(include)


#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cxx")

# sources to include
#include_directories ("${PROJECT_SOURCE_DIR}/common_ds")
#include_directories("${PROJECT_BINARY_DIR} COMMON_DS_DIR")
#add_subdirectory(common_ds)
#ADD_EXECUTABLE(stacks_main  main.cpp ${Dir1_Sources})
ADD_EXECUTABLE(iterators_main  ${SOURCES})
#target_link_libraries(stacks_main common_ds)
