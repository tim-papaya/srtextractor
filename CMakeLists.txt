cmake_minimum_required(VERSION 3.5)

project(subtranslator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("subtranslator")

add_subdirectory ("srtcreator")
add_subdirectory ("srtreader")
add_subdirectory ("libsubtranslator")

