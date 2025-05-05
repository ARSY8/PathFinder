#include <fstream>
#include <string>
#include <sstream>
#include <vector>


using std::ios;

class ReaderWriter {
    ReaderWriter() = delete;
    ~ReaderWriter() = delete;
public:
    static void fileReader(const std::string& fileName, std::vector<int>& maze);
    static void fileWriter(const std::vector<int>& maze, const std::pair<int, int>);
    static const std::pair<int, int> get_cols_rows(const std::string& fileName);
};