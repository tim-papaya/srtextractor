cmake_minimum_required(VERSION 3.5)

project(subtranslator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("subtranslator")

set(READER_EXE src/main.cpp)

set(SOURCE_LIB src/srtextractor.h
               src/srtextractor.cpp)

add_library(sublib STATIC ${SOURCE_LIB})

add_executable(srtextr ${READER_EXE})
target_link_libraries(srtextr sublib)
