#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>


class PathFinder {
    std::vector<int> maze{ nullptr };
    std::unordered_map<int, std::vector<int>> adjList{ nullptr };
    std::vector<int> dist;
    std::vector<int> from;
    int cols{ 0 };
    int rows{ 0 };
    int heroVertex{ -1 };
    int escapeVertex{ -1 };
    int graphSize{ 0 };

public:
    PathFinder(std::vector<int>& maze, std::pair<int, int> cols_rows);
    ~PathFinder();

    void getPath();
private:
    int getGraphSize();
    void getAdjList();
    void bfs();
};
