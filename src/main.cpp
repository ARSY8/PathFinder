#include <iostream>
#include <string>
#include <vector>
#include "FileReaderWriter.hpp"
#include "PathFinder.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Использование: " << argv[0] << " <имя файла с лабиринтом>\n";
        return 1;
    }

    std::string fileName = argv[1];

    // Создаем вектор для хранения лабиринта
    std::vector<int>* maze = new std::vector<int>;

    try {
        // Читаем лабиринт из файла
        ReaderWriter::fileReader(fileName, maze);
        
        // Получаем размеры лабиринта
        auto cols_rows = ReaderWriter::get_cols_rows(fileName);
        int cols = cols_rows.first;
        int rows = cols_rows.second;

        // Создаем объект PathFinder для поиска пути
        PathFinder pathFinder(maze, cols_rows);

        // Получаем найденный путь и обновляем лабиринт
        pathFinder.getPath();

        // Записываем результат в файл
        ReaderWriter::fileWriter(maze, {cols, rows});

        std::cout << "Путь успешно найден и записан в файл path.txt\n";

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
        delete maze;
        return 1;
    }
    delete maze;

    return 0;
}
