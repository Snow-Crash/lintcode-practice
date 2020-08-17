// 1602-Decoded-String-at-Index.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param S: An encoded string.
     * @param K: An index.
     * @return: Return the K-th letter (1 indexed) in the decoded string.
     */
    string decodeAtIndex(string& S, int K) {
        // Write your code here.

        long len = 0;

        int i = 0;

        for (; i < S.size() && len < K; i++)
        {
            if (S[i] >= 'a' && S[i] <= 'z')
                len++;
            else
                len = len * (S[i] - '0');
        }

        i--;

        while (i>=0)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                len = len / (S[i] - '0');
                K = K % len;
            }
            else
            {
                if (K % len == 0)
                    return S.substr(i, 1);
                else
                    len--;
            }
            i--;
        }
    }
};

int main()
{
    string s1 = "lint2code3";
    string s2 = "ha22";

    Solution solution;

    string res = solution.decodeAtIndex(s2, 5);
}
