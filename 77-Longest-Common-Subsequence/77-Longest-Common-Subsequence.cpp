// 77-Longest-Common-Subsequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string& A, string& B) {
        // write your code here

        vector<vector<int>> mem(A.size(), vector<int>(B.size(), -1));

        int maxlen = dfs(A, B, 0, 0, mem);

        return maxlen;

    }

    int dfs(string& a, string& b, int i, int j, vector<vector<int>>& mem)
    {

        if (i == a.size() || j == b.size())
        {
            return 0;
        }

        if (mem[i][j] != -1)
            return mem[i][j];

        int length = 0;

        if (a[i] == b[j])
        {
            length = dfs(a, b, i + 1, j + 1, mem) + 1;
        }
        else
        {
            int len_1 = dfs(a, b, i + 1, j, mem);
            int len_2 = dfs(a, b, i, j + 1, mem);

            length = max(len_1, len_2);
        }

        mem[i][j] = length;

        return length;

    }

};

int main()
{

    string a = "bedaacbade";
    string b = "dccaeedbeb";
    
    Solution solution;

    int result = solution.longestCommonSubsequence(a, b);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
