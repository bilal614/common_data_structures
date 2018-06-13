cmake_minimum_required (VERSION 2.8)

# This is the name of the project
PROJECT(data_structure_circle_ll)

# This is for recursively searching for other directories.
# add_subdirectory (DirectoryName)

# sources to include
include_directories("${PROJECT_BINARY_DIR}")
ADD_EXECUTABLE(circle_ll_main  main.cxx)


