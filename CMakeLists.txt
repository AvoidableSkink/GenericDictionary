cmake_minimum_required(VERSION 3.6)
project(GenericDictionary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h KeyValue.cpp KeyValue.h)
add_executable(GenericDictionary ${SOURCE_FILES})