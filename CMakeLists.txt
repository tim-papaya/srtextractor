cmake_minimum_required(VERSION 3.5)

project(subtranslator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("subtranslator")

set(READER_EXE src/reader.cpp)
set(WRITER_EXE src/writer.cpp)

set(SOURCE_LIB src/srtreader.h
               src/srtreader.cpp
               src/srtwriter.h
               src/srtwriter.cpp)

add_library(sublib STATIC ${SOURCE_LIB})

add_executable(readsrc ${READER_EXE})
target_link_libraries(readsrc sublib)

add_executable(writesrc ${WRITER_EXE})
target_link_libraries(writesrc sublib)

