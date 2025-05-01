#include <iostream>
#include <string>
#include <vector>
#include "FileReaderWriter.hpp"
#include "PathFinder.hpp"

int main() {

    std::string fileName = "maze.txt";

    std::vector<int>* maze = new std::vector<int>;

    try {
        ReaderWriter::fileReader(fileName, maze);

        auto cols_rows = ReaderWriter::get_cols_rows(fileName);
        int cols = cols_rows.first;
        int rows = cols_rows.second;

        PathFinder pathFinder(maze, cols_rows);

        pathFinder.getPath();

        ReaderWriter::fileWriter(maze, { cols, rows });

        std::cout << "Путь успешно найден и записан в файл path.txt\n";

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        delete maze;
        return 1;
    }
    delete maze;

    return 0;
}