cmake_minimum_required (VERSION 2.8)

# This is the name of the project
PROJECT(data_structure_dbl_ll)

# This is for recursively searching for other directories.
# add_subdirectory (DirectoryName)

# sources to include
include_directories("${PROJECT_BINARY_DIR}")
ADD_EXECUTABLE(dbl_ll_main  main.cpp)


