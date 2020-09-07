// 3-384-longest-substring-without-repeating-characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/longest-substring-without-repeating-characters
// https://www.lintcode.com/problem/longest-substring-without-repeating-characters/description

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 0)
            return 0;

        int left = 0;
        int right = 0;

        int begin = 0;
        int end = 0;

        int maxLen = INT_MIN;

        unordered_map<char, int> count;

        for (; right < s.size(); right++)
        {
            char c = s[right];

            count[c]++;

            if (count[c] == 1)
            {
                if (right - left + 1 > maxLen)
                {
                    maxLen = right - left + 1;
                    begin = left;
                    end = right;
                }
            }
            else
            {
                while (count[c] > 1)
                {
                    count[s[left]]--;
                    left++;
                }
            }
        }
        return maxLen;
    }
};

int main()
{
    string s1 = "abcabcbb";

    string s2 = "pwwkew";

    Solution solution;
    
    int res = solution.lengthOfLongestSubstring(s2);
}
