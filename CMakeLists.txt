cmake_minimum_required(VERSION 3.10.2)
project(Scheduling-Algorithms)
set (EXE_NAME Scheduling-Algorithms)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 testData.txt)


#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(Scheduling-Algorithms main.cpp roundRobin.cpp priority.cpp calculations.cpp readFiles.cpp)