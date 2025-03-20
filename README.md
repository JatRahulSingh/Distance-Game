# Game Name: Distance
Description:
Distance is a grid-based pathfinding game where the player must navigate from the top-left corner of a randomly generated grid to the bottom-right corner while minimizing the total cost. The game challenges players to find the optimal path by strategically moving through cells with lower values.

# Gameplay:
1-The grid consists of randomly generated numbers (1-9), representing the movement cost of each cell.

2-The player controls a character (P) and moves using the WASD keys.

3-The goal is to reach the bottom-right corner with the minimum possible score, matching the optimal path computed by an algorithm.

4-If the player's path does not match the expected optimal cost, they can retry or get hints.

# Features:
1-Random Grid Generation: Each level presents a unique challenge.

2-Pathfinding Challenge: Uses Dijkstra’s algorithm to calculate the optimal path.

3-Increasing Difficulty: Grid size grows with each level, making navigation harder.

4-Hints & Retry Option: Players can request hints or retry levels for better performance.

# Winning Condition:
1-The player wins a level if they match the optimal path's score.

2-The game is completed upon successfully solving all levels up to a 10x10 grid.

# Losing Condition:
1-If the player's total movement cost is incorrect and they choose not to retry, the game ends.

# Technical Aspects:
1-Implemented in C++ using priority queues for pathfinding.

2-Uses Dijkstra’s algorithm to compute the minimum path sum.

3-Terminal-based display with real-time movement updates.

4-_getch() (Windows) for real-time input handling.

# Ouput:
![Screenshot 2025-03-20 222048](https://github.com/user-attachments/assets/bee258f8-f659-4a12-91e9-47f62a539432)

![Screenshot 2025-03-20 222131](https://github.com/user-attachments/assets/bd7830e8-abb6-4f4f-ae71-d7a9d09b0aa7)

![Screenshot 2025-03-20 222140](https://github.com/user-attachments/assets/32799060-c989-4259-ab50-59033032210a)

