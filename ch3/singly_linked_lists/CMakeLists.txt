cmake_minimum_required (VERSION 2.8)

# This is the name of the project
PROJECT(data_structure_sll)

# This is for recursively searching for other directories.
# add_subdirectory (DirectoryName)

#file(GLOB Sources "*.h")
#add_library(Dir1 STATIC ${Sources})

# sources to include
include_directories("${PROJECT_BINARY_DIR}")
ADD_EXECUTABLE(sll_main  main.cpp)


