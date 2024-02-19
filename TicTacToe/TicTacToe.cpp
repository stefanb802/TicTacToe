// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Keeps track of the current player
bool isX = true;

static bool checkRow(char grid[3][3], int i) {
    return (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ');
}

static bool checkCol(char grid[3][3], int j) {
    return (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j] && grid[0][j] != ' ');
}

static bool checkDiag(char grid[3][3]) {
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ')
        return true;
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ')
        return true;
    return false;
}

static bool isFull(char grid[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == ' ')
                return false;
    return true;
}

//Checks if there is a winner
static bool isOver(char grid[3][3]) {
    
    for(int i=0; i<3; i++)
        if(checkCol(grid, i) || checkRow(grid, i) || checkDiag(grid))
            if (isX) {
                cout << "Game over! O wins!" << endl;
                return true;
            }
            else {
                cout << "Game over! X wins!" << endl;
                return true;
            }
    if (isFull(grid)) {
        cout << "Game over! It's a draw!" << endl;
        return true;
    }
    return false;
}

static bool isLegal(int row, int col, char grid[3][3]) {
    return grid[row][col] == ' ';
}

//Handles the user's input
static void getMove(char grid[3][3]) {
    if (isX)
        cout << "X's turn!" << endl;
    else
        cout << "O's turn!" << endl;
    cout << "Insert row and column!"<<endl;
    int row, col;
    cin >> row >> col;
    while (!isLegal(row, col, grid)) {
        cout << "Illegal move! Insert different values!" << endl;
        cin >> row >> col;
    }
    if (isX)
        grid[row][col] = 'X';
    else
        grid[row][col] = 'O';
    isX = !isX;
}


static void printGrid(char grid[3][3]) {
    cout << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << endl;
    cout << "- - -"<<endl;
    cout << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << endl;
    cout << "- - -" << endl;
    cout << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;

}

int main()
{
    char grid[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    while (!isOver(grid)) {
        printGrid(grid);
        getMove(grid);
    }
    printGrid(grid);
    return 0;

}

