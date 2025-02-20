#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int chunkOfCheese(vector<vector<int>> maze) {
    int rows = maze.size();
    int cols = maze[0].size();

    // Directions for moving up, down, left, right
    int dirX[] = {0, 0, -1, 1};
    int dirY[] = {-1, 1, 0, 0};

    // BFS queue
    queue<pair<int, int>> q;
    q.push({0, 0});

    // Visited array to track the cells we have already processed
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[0][0] = true;

    // BFS loop
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Check if we've found the cheese
        if (maze[x][y] == 9) {
            return 1; // Cheese found
        }

        // Explore neighbors in four possible directions
        for (int i = 0; i < 4; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            // Check if the new position is valid
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && maze[newX][newY] != 0 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    // If we exit the loop without finding the cheese, return 0
    return 0;
}

int main() {
    // Input for maze_row and maze_col
    int maze_row, maze_col;
    cin >> maze_row >> maze_col;

    // Input for the maze
    vector<vector<int>> maze(maze_row, vector<int>(maze_col));
    for (int i = 0; i < maze_row; ++i) {
        for (int j = 0; j < maze_col; ++j) {
            cin >> maze[i][j];
        }
    }

    // Output whether cheese is reachable
    cout << chunkOfCheese(maze) << endl;

    return 0;
}
