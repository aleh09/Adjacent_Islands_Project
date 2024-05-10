/***********************************************************
Program: Project_2_Islands.cpp
Purpose: Write code to count the number of islands in 2D grid
Author: Andy Lehmann
Date: December 10, 2023
************************************************************/

#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Island
{
public:
    // Function to count the number of islands in the given grid
    int numIslands(vector<vector<int>>& grid);
private:
    // Depth-First Search (DFS) function to explore connected land cells
    void dfs(vector<vector<int>>& grid, int row, int col);
};

// Implementation of the function to count the number of islands
int Island::numIslands(vector<vector<int>>& grid)
{
    // Check if the grid is empty
    if (grid.empty() || grid[0].empty()) {
        return 0; // If empty, there are no islands
    }

    // Get the number of rows and columns in the grid
    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0; // Variable to store the count of islands

    // Iterate through each cell in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If the current cell is land (1), initiate DFS and increment the island count
            if (grid[i][j] == 1) {
                ++islandCount;
                dfs(grid, i, j);
            }
        }
    }

    // Return the total number of islands in the grid
    return islandCount;
}

// Implementation of the Depth-First Search (DFS) function
void Island::dfs(vector<vector<int>>& grid, int row, int col)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Base case: If the current cell is out of bounds or water, return
    if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != 1) {
        return;
    }

    stack<pair<int, int>> stk;
    stk.push(std::make_pair(row, col));

    while (!stk.empty()) {
        auto current = stk.top();
        stk.pop();

        int r = current.first;
        int c = current.second;

        // Mark the current cell as visited
        grid[r][c] = -1;

        // Push neighboring land cells onto the stack if they are not visited
        if (r + 1 < rows && grid[r + 1][c] == 1) stk.push(std::make_pair(r + 1, c));
        if (r - 1 >= 0 && grid[r - 1][c] == 1) stk.push(std::make_pair(r - 1, c));
        if (c + 1 < cols && grid[r][c + 1] == 1) stk.push(std::make_pair(r, c + 1));
        if (c - 1 >= 0 && grid[r][c - 1] == 1) stk.push(std::make_pair(r, c - 1));
    }
}