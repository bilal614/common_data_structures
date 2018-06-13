cmake_minimum_required (VERSION 2.8)


# This is the name of the project
PROJECT(data_structure_iterators C CXX)


#add_subdirectory(COMMON_DS_DIR)


# sources to include
#include_directories ("${PROJECT_SOURCE_DIR}/common_ds")
#include_directories("${PROJECT_BINARY_DIR} COMMON_DS_DIR")
#add_subdirectory(common_ds)
#ADD_EXECUTABLE(stacks_main  main.cpp ${Dir1_Sources})
ADD_EXECUTABLE(iterators_main  main.cxx )
#target_link_libraries(stacks_main common_ds)
