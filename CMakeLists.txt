cmake_minimum_required(VERSION 3.10)

project(PathFinder)

# Задаем стандарт C++
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(googletest)


# Создаем библиотеку
add_library(
    FileReaderWriter
    src/FileReaderWriter.cpp
    src/FileReaderWriter.hpp
)

add_library(
    PathFinder
    src/PathFinder.cpp
    src/PathFinder.hpp
)

# Создаем исполняемый файл для тестов
add_executable(
    PathFinderTest
    test/PathFinderTests.cpp
)

# Подключаем заголовочные файлы
target_include_directories(
    PathFinder PRIVATE
    FileReaderWriter PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_include_directories(
    PathFinderTest PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/maze.txt
    COPYONLY
)

# Линкуем
target_link_libraries(
    PathFinderTest PRIVATE
    gtest
    gtest_main
    PathFinder
    FileReaderWriter
)