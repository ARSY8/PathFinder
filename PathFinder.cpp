#include "PathFinder.hpp"
#include "FileReaderWriter.hpp"


int INF = 1e9;

PathFinder::PathFinder(std::vector<int>* maze, const std::pair<int, int> cols_rows) {
    cols = cols_rows.first;
    rows = cols_rows.second;

    PathFinder::maze = maze;

    graphSize = getGraphSize();

    dist = new std::vector<int>(cols*rows, INF);
    adjList = new std::unordered_map<int, std::vector<int>>;
    from = new std::vector<int>(cols*rows, -1);

    getAdjList();
    bfs();

}

PathFinder::~PathFinder() {
    delete adjList;
    delete dist;
    delete from;
}


int PathFinder::getGraphSize() {
    int graph_size{ 0 };

    for (auto i : *maze) {
        if (i == 3 || i == 0 || i == 2) {
            graph_size++;
        }
    }

    return graph_size;
}

void PathFinder::getAdjList() {
    std::vector<int>& maze_ = *maze;
    std::unordered_map<int, std::vector<int>>& adjList_ = *adjList;
    int vertex{ 0 };
    int neighbour{ 0 };

    bool doneH{ false };
    bool doneE{ false };

    for (int rows_ = 0; rows_ < rows; ++rows_) {
        for (int cols_ = 0; cols_ < cols; ++cols_) {
            vertex = rows_ * cols + cols_;
            if (maze_[vertex] == 1);
            else {
                if (maze_[vertex] == 2 && !doneH) {
                    heroVertex = vertex;
                    doneH = true;
                }
                if (maze_[vertex] == 3 && !doneE) {
                    escapeVertex = vertex;
                    doneE = true;

                }


                int directions[4] = { 1, -1, cols, -cols };

                for (int dir : directions) {
                    neighbour = vertex + dir;

                    if (dir == 1 && (vertex + 1) % cols == 0) continue;
                    if (dir == -1 && vertex % cols == 0) continue;

                    if (neighbour >= maze_.size() || neighbour < 0) {
                        continue;
                    }

                    if (maze_[neighbour] == 0 || maze_[neighbour] == 2 || maze_[neighbour] == 3) {
                        adjList_[vertex].push_back(neighbour);
                    }
                }
            }
        }
    }

    if (heroVertex < 0 || heroVertex >= maze_.size()) {
        throw std::runtime_error("Не найдена вершина героя");
    }
    if (escapeVertex < 0 || escapeVertex >= maze_.size()) {
        throw std::runtime_error("Не найдена вершина выхода");
    }
}




void PathFinder::bfs() {

    std::unordered_map<int, std::vector<int>>& adjList_ = *adjList;
    std::vector<int>& from_ = *from;
    std::vector<int>& dist_ = *dist;
    std::queue<int> q;

    dist_[heroVertex] = 0;
    q.push(heroVertex);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int target_vertex : adjList_[vertex]) {
            if (dist_[target_vertex] > dist_[vertex] + 1) {
                dist_[target_vertex] = dist_[vertex] + 1;
                from_[target_vertex] = vertex;
                q.push(target_vertex);
            }
        }
    }
}


void PathFinder::getPath() {
    std::vector<int> path;
    std::vector<int>& from_ = *from;

    if (from_[escapeVertex] == -1) {
        throw std::runtime_error("Путь к выходу закрыт.");
    }

    for (int vertex = escapeVertex; vertex != -1; vertex = from_[vertex]) {

        (*maze)[vertex] = 8;
    }
}