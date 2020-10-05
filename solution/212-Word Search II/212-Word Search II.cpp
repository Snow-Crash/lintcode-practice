// 212-Word Search II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int m = board.size();
        if (m == 0)
            return vector<string>();

        int n = board[0].size();
        if (n == 0)
            return vector<string>();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<string> result;

        unordered_set<string> table(words.begin(), words.end());

        string path = "";

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, table, visited, result, path, i, j);
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& board, unordered_set<string>& words, vector<vector<int>>& visited,
        vector<string>& result, string path, int row, int col)
    {
        //if (row < 0 || row >= board.size() || col <= 0 || col >= board[0].size())
        //    return;

        //if (visited[col][row] == 1)
        //    return;

        if (words.count(path) > 0)
        {
            result.push_back(path);
            return;
        }

        vector<vector<int>> dir{ {0,1},{0,-1},{1,0},{-1,0} };

        for (int i = 0; i < dir.size(); i++)
        {
            int n_row = row + dir[i][0];
            int n_col = col + dir[i][1];

            if (n_row < 0 || n_row >= board.size() || n_col < 0 || n_col >= board[0].size() || visited[n_row][n_col] == 1)
                continue;

            visited[n_row][n_col] = 1;
            dfs(board, words, visited, result, path + board[n_row][n_col], n_row, n_col);
            visited[n_row][n_col] = 1;
        }


    }
};

int main()
{
    Solution solution;

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<string> words = { "oath", "pea", "eat", "rain" };

    vector<string> result = solution.findWords(board, words);
}
