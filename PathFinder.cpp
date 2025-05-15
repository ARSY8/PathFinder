#include <limits>
#include "PathFinder.hpp"
#include "FileReaderWriter.hpp"


PathFinder::PathFinder(std::vector<int>& maze_, const std::pair<int, int> cols_rows) : maze{maze_} {
    cols = cols_rows.first;
    rows = cols_rows.second;

    graphSize = getGraphSize();

    dist.resize( cols * rows,  std::numeric_limits<unsigned int>::max());
    from.resize( cols * rows, -1 );

    try{
        getAdjList();
    }
    catch (const std::exception& e) {
        throw;
    }
    bfs();
}


int PathFinder::getGraphSize() {
    int graph_size{ 0 };

    for (auto i : maze) {
        if (i == 3 || i == 0 || i == 2) {
            graph_size++;
        }
    }

    return graph_size;
}

void PathFinder::getAdjList() {
    int vertex{ 0 };
    int neighbour{ 0 };

    bool doneH{ false };
    bool doneE{ false };

    for (int rows_ = 0; rows_ < rows; ++rows_) {
        for (int cols_ = 0; cols_ < cols; ++cols_) {
            vertex = rows_ * cols + cols_;
            if (maze[vertex] == 1);
            else {
                if (maze[vertex] == 2 && !doneH) {
                    heroVertex = vertex;
                    doneH = true;
                }
                if (maze[vertex] == 3 && !doneE) {
                    escapeVertex = vertex;
                    doneE = true;

                }


                int directions[4] = { 1, -1, cols, -cols };

                for (int dir : directions) {
                    neighbour = vertex + dir;

                    if (dir == 1 && (vertex + 1) % cols == 0) continue;
                    if (dir == -1 && vertex % cols == 0) continue;

                    if (neighbour >= maze.size() || neighbour < 0) {
                        continue;
                    }

                    if (maze[neighbour] == 0 || maze[neighbour] == 2 || maze[neighbour] == 3) {
                        adjList[vertex].push_back(neighbour);
                    }
                }
            }
        }
    }

    if (heroVertex < 0 || heroVertex >= maze.size()) {
        throw std::runtime_error("Не найдена вершина героя");
    }
    if (escapeVertex < 0 || escapeVertex >= maze.size()) {
        throw std::runtime_error("Не найдена вершина выхода");
    }
}



void PathFinder::bfs() {
    std::queue<int> q;

    dist[heroVertex] = 0;
    q.push(heroVertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int target_vertex : adjList[vertex]) {
            if (dist[target_vertex] > dist[vertex] + 1) {
                dist[target_vertex] = dist[vertex] + 1;
                from[target_vertex] = vertex;
                q.push(target_vertex);
            }
        }
    }
}


void PathFinder::getPath() {
    if (from[escapeVertex] == -1) {
        throw std::runtime_error("Путь к выходу закрыт.");
    }

    for (int vertex = escapeVertex; vertex != -1; vertex = from[vertex]) {

        maze[vertex] = 8;
    }
}