#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <conio.h> // For _getch() on Windows, use <ncurses.h> on Linux

using namespace std;

struct Cell {
    int x, y, cost;
    bool operator>(const Cell &other) const {
        return cost > other.cost;
    }
};

void generateGrid(vector<vector<int>> &grid, int size) {
    grid.resize(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 9 + 1;
        }
    }
}

void displayGrid(const vector<vector<int>> &grid, int px, int py) {
    system("cls"); // For Windows, use "clear" for Linux
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (i == px && j == py) cout << "P ";
            else cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    pq.push({0, 0, grid[0][0]});
    dist[0][0] = grid[0][0];
    
    while (!pq.empty()) {
        Cell curr = pq.top(); pq.pop();
        if (curr.x == n - 1 && curr.y == n - 1) return curr.cost;
        
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                int newCost = curr.cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({nx, ny, newCost});
                }
            }
        }
    }
    return -1;
}

bool playGame(vector<vector<int>> &grid, int expectedResult) {
    int x = 0, y = 0, playerScore = grid[0][0];
    char move;
    int n = grid.size();
    
    while (x != n - 1 || y != n - 1) {
        displayGrid(grid, x, y);
        cout << "Score: " << playerScore << "\n";
        cout << "Use WASD to move: ";
        move = _getch();
        
        int newX = x, newY = y;
        if (move == 's' || move== 'S') newX++;
        else if (move == 'w' || move== 'W') newX--;
        else if (move == 'a' || move== 'A') newY--;
        else if (move == 'd' || move== 'D') newY++;
        else {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        
        if (newX < 0 || newY < 0 || newX >= n || newY >= n) {
            cout << "Out of bounds! Try a different move.\n";
            continue;
        }
        
        x = newX;
        y = newY;
        playerScore += grid[x][y];
    }
    
    displayGrid(grid, x, y);
    if (playerScore == expectedResult) {
        cout << "Congratulations! You completed the level!\n";
        return true;
    } else {
        cout << "Incorrect path! Expected: " << expectedResult << "\n";
        char hintChoice;
        cout << "Do you want a hint? (y/n): ";
        cin >> hintChoice;
        if (hintChoice == 'y' || hintChoice == 'Y') {
            cout << "Hint: Try moving towards cells with smaller numbers. The optimal path has a total cost of: " << expectedResult << "\n";
        }
        char retryChoice;
        cout << "Do you want to retry? (y/n): ";
        cin >> retryChoice;
        if (retryChoice == 'y' || retryChoice == 'Y') {
            return playGame(grid, expectedResult);
        }
        return false;
    }
}

int main() {
    srand(time(0));
    int level = 1, gridSize = 3, maxSize = 10;
    
    while (gridSize <= maxSize) {
        vector<vector<int>> grid;
        generateGrid(grid, gridSize);
        cout << "Level: " << level << " (Grid Size: " << gridSize << "x" << gridSize << ")\n";
        
        int expectedResult = minPathSum(grid);
        
        if (!playGame(grid, expectedResult)) {
            cout << "Game Over!\n";
            break;
        }
        gridSize++;
        level++;
    }
    if (gridSize > maxSize) cout << "Congratulations! You've completed the game!\n";
    return 0;
}
