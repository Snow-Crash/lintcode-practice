// 79-word search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        if (m == 0)
            return false;

        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //     if (board[i][j] != word[0])
                //         continue;

                visited[i][j] = 1;
                bool found = dfs(board, visited, word, 0, i, j);
                visited[i][j] = 0;

                if (found == true)
                    return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string& word, int depth, int x, int y)
    {
        if (board[x][y] != word[depth])
            return false;

        if (depth == word.size() - 1)
            return true;

        vector<vector<int>> dirs{ {0,1}, {1,0}, {-1,0}, {0,-1} };

        for (int i = 0; i < dirs.size(); i++)
        {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];

            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size() || visited[nx][ny] == 1)
                continue;

            visited[nx][ny] = 1;
            bool found = dfs(board, visited, word, depth + 1, nx, ny);
            visited[nx][ny] = 0;

            if (found == true)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board{ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
    string word = "ABCCED";


    vector<vector<char>> board2 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    
    string word2 = "ABCB";

    Solution solution;

    bool res = solution.exist(board2, word2);
}
