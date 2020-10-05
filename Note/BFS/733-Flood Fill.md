# 733.Flood Fill

<https://leetcode.com/problems/flood-fill>

## Summary

Use BFS. Start from the given coordinate. Push the starting point into a queue. Then start BFS. Each coordinate has four neighbors, when push neighbors into queue, check if next coordinate is valid/visited, and the color is desired color.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int m =image.size();
        int n = 0;
        if (m != 0)
            n = image[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<vector<int>> q;

        // the color that will be replaced by newColor
        int color = image[sr][sc];

        q.push({sr, sc});

        // used to iterate four directions
        vector<vector<int>> dirs{{0,1}, {1, 0}, {0,-1}, {-1, 0}};

        while(q.empty() == false)
        {
            // get a coordinate from queue
            vector<int> curr = q.front();

            int cr = curr[0];
            int cc = curr[1];

            // replace its color
            image[cr][cc] = newColor;

            q.pop();

            visited[curr[0]][curr[1]] = 1;

            // discover its neighbors
            for(int i = 0; i < dirs.size(); i++)
            {
                int nr = dirs[i][0] + cr;
                int nc = dirs[i][1] + cc;

                // only when the coordinate is valid, and the color is target color, and the coordinate is not visited, push the coordinate into queue
                if (nr < m && nc < n && nr >= 0 && nc >= 0 && visited[nr][nc] == 0 && image[nr][nc] == color)
                    q.push({nr, nc});
            }
        }

        return image;
    }
};
```
