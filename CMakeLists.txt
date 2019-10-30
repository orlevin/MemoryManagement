#Set the minimum version of cmake for this project
cmake_minimum_required(VERSION 2.8.12.2)

#set the project name
project(directory_test2)
 
#Add the necessary files to the project
file(GLOB SOURCES /home/ubuntu/workspace/src/*.cpp /home/ubuntu/workspace/src/*.hpp)

#set compiling flags
add_compile_options(-std=c++11)
 
#ask for an executable to be built using the SOURCES variable containing the files added
add_executable(project ${SOURCES})