#include "FileReaderWriter.hpp"


void ReaderWriter::fileReader(const std::string& fileName, std::vector<int>& maze) {



    std::ifstream ifs(fileName);

    if (ifs.is_open()) {
        int number{ 0 };
        std::string line;
        while (std::getline(ifs, line)) {
            std::istringstream iss(line);

            while (iss >> number) {
                maze.push_back(number);
            }
        }
        ifs.close();
    }
    else {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }
}

void ReaderWriter::fileWriter(const std::vector<int>& maze, const std::pair<int, int> cols_rows) {
    std::ofstream ofs("path.txt");

    int cols = cols_rows.first;
    int rows = cols_rows.second;

    if (ofs.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ofs << maze[i * cols + j] << ' ';
            }
            ofs << '\n';
        }
        ofs.close();
    }
    else {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }
}


const std::pair<int, int> ReaderWriter::get_cols_rows(const std::string& fileName) {
    std::ifstream ifs(fileName);

    if (ifs.is_open()) {
        std::string line;
        bool firstLine{ true };
        int number{ 0 };
        int countCols{ 0 };
        int countRows{ 0 };
        while (std::getline(ifs, line)) {
            countRows++;
            if (firstLine) {
                std::istringstream iss(line);
                while (iss >> number) {
                    countCols++;
                }
                firstLine = false;
            }
        }
        ifs.close();
        return { countCols, countRows };
    }
    else {
        throw std::runtime_error("Не удалось открыть файл");
    }
}