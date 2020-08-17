// 1246-Longest-Repeating-Character-Replacement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @param k: a integer
     * @return: return a integer
     */
    int characterReplacement(string& s, int k) {
        // write your code here

        int left = 0;
        int right = 0;

        unordered_map<char, int> m;

        int max_len = 0;

        for (right = 0; right != s.size(); right++)
        {
            m[s[right]] ++;

            max_len = max(max_len, m[s[right]]);

            if (right - left + 1 > max_len + k)
            {
                m[s[left]] --;
                left++;
            }
        }
        return right - left;
    }
};

int main()
{
    string a = "ABAB";

    Solution solution;

    solution.characterReplacement(a, 0);
}