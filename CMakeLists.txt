cmake_minimum_required(VERSION 3.10)

project(PathFinder)

# Задаем стандарт C++
set(CMAKE_CXX_STANDARD 23)

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

# Создаем исполняемый файл
add_executable(
    main
    src/main.cpp
)

# Подключаем заголовочные файлы
target_include_directories(
    PathFinder PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# Линкуем
target_link_libraries(
    main PRIVATE 
    PathFinder
    FileReaderWriter
)

# Опции компиляции

target_compile_options(
    PathFinder PRIVATE
    -Wall -Wextra -pedantic -Werror
)

target_compile_options(
    FileReaderWriter PRIVATE
    -Wall -Wextra -pedantic -Werror
)

target_compile_options(
    main PRIVATE
    -Wall -Wextra -pedantic -Werror
)

# if(MSVC){
#     set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#     target_compile_options(
#         CircularBuffer PRIVATE
#         /W4
#     )

#     target_compile_options(
#         CircularBufferTests PRIVATE
#         /W4
#     )
# }
