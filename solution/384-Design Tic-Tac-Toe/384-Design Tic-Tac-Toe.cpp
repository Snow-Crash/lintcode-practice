// 384-Design Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {

        grid = vector<vector<int>>(n, vector<int>(n, 0));

        size = n;
    }

    int size;
    vector<vector<int>> grid;

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {

        grid[row][col] = player;

        int res = check(row, col, player);

        return res;
    }

    int check(int row, int col, int player)
    {
        int cnt = 0;
        //check row
        for (int i = 0; i < size; i++)
        {
            if (grid[row][i] == player)
                cnt++;
        }

        if (cnt == size)
            return player;

        cnt = 0;
        //check col
        for (int i = 0; i < size; i++)
        {
            if (grid[i][col] == player)
                cnt++;
        }

        if (cnt == size)
            return player;

        cnt = 0;

        for (int i = 0; i < size; i++)
        {
            if (grid[i][i] == player)
                cnt++;
        }

        if (cnt == size)
            return player;

        cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (grid[i][size - i - 1] == player)
                cnt++;
        }

        if (cnt == size)
            return player;

        return 0;

    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main()
{
    TicTacToe ttt(3);

    int res = 0;
    res = ttt.move(0, 0, 1);
    res = ttt.move(0, 2, 2);
    res = ttt.move(2, 2, 1);
    res = ttt.move(1, 1, 2);
    res = ttt.move(2, 0, 1);
    res = ttt.move(1, 0, 2);
    res = ttt.move(2, 1, 1);
}

