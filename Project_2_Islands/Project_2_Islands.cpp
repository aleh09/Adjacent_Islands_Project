/***********************************************************
Program: Project_2_Islands.cpp
Purpose: Write code to count the number of islands in 2D grid
Author: Andy Lehmann
Date: December 10, 2023
************************************************************/

#include "IslandClass.h"
#include <fstream>

int main() {
    ifstream inputFile("Test_Islands1.txt"); //You can change the name of the input file to the desired island to run program on

    //make sure the file can be opened
    if (!inputFile.is_open()) {
        cerr << "Unable to open input file." << endl;
        return 1;
    }

    //the first number in the file is the cols and the second is the rows
    int rows, cols;
    inputFile >> cols >> rows;

    vector<vector<int>> grid(rows, vector<int>(cols));

    //create the grid from the input file to be used by the islands class
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputFile >> grid[i][j];
        }
    }

    inputFile.close();

    Island island; //create instance of islands class
    int numIslands = island.numIslands(grid); //run numIslands function on the grid inputted from file

    cout << "Number of islands: " << numIslands << endl; //return number of islands

    return 0;
}

