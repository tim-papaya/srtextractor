cmake_minimum_required(VERSION 3.5)

project(subtranslator LANGUAGES CXX)

set(SOURCE_LIB "main.cpp")
add_library(libtemplates STATIC ${SOURCE_LIB})
add_executable (templates "main.cpp")

target_link_libraries(templates libtemplates)
