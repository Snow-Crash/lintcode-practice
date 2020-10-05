# 48. Rotate Image

<https://leetcode.com/problems/rotate-image/>

## Summary

 Clockwise rotate: flip the matrix up to down, and then transpose it.
 Anticlockwise: flip left to right, and then transpose it

## Solution 1

```cpp
// https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
```

## Solution 2

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < n / 2 + n % 2; i++)
        {
            for (int j = i; j < n - i-1; j++)
            {

                //save left
                int temp = matrix[j][i];

                //bottom to left
                matrix[j][i] = matrix[n - i - 1][j];

                // right to bottom
                matrix[n-i-1][j] = matrix[n-j-1][n-i-1];

                //top to right
                matrix[n-j-1][n-i-1] = matrix[i][n-j-1];

                //left to top
                matrix[i][n - j - 1] = temp;
            }
        }
    }
};
```

## Reference

<https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image>
