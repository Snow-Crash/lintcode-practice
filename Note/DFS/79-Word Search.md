# 79. Word Search

## Summary

Do DFS at every position of the board. Record the depth d of DFS. If dth character of word does not equal to current character of DFS, return false. If the depth equals to the length of word, this means the word is found.

## Solution

```cpp
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
        // if current char is not the same as dth char in word, no need to do dfs, return false.
        if (board[x][y] != word[depth])
            return false;

        // This means the search finally reaches the end of word,return true
        if (depth == word.size() - 1)
            return true;

        vector<vector<int>> dirs{ {0,1}, {1,0}, {-1,0}, {0,-1} };

        for (int i = 0; i < dirs.size(); i++)
        {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];

            // check boundaries, and do not search visited chars again
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
```
