# 22. Generate Parentheses

<https://leetcode.com/problems/generate-parentheses>

## Summary


## Solution

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;

        string path = "";

        dfs(result, path + '(', 1, 1, n);

        return result;
    }

    void dfs(vector<string> &result, string path, int depth, int cnt, int n)
    {
        if (depth == n*2)
        {
            if (cnt == 0)
                result.push_back(path);
            return;
        }

        if (cnt == -1)
            return;

        dfs(result, path+'(', depth+1, cnt+1, n);

        dfs(result, path+ ')',depth+1, cnt-1, n);


    }
};
```
