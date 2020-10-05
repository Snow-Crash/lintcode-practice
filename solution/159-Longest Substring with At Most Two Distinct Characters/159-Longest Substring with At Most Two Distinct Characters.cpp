// 159-Longest Substring with At Most Two Distinct Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        if (s.size() == 0)
            return 0;

        int l = 0;
        int r = 0;

        unordered_map<char, int> m;

        int cnt = 0;

        int window = INT_MIN;

        while (r < s.size())
        {
            char curr = s[r];

            if (m[curr] == 0)
                cnt++;

            m[curr]++;


            if (cnt <= 2)
                window = max(window, r - l + 1);

            // reduce window size
            while (cnt > 2)
            {
                char discard = s[l];

                m[discard]--;

                if (m[discard] == 0)
                    cnt--;

                l++;
            }
            r++;
        }
        return window;
    }
};

int main()
{
    string s = "eceba";
    string s2 = "abaccc";
    
    Solution solution;

    int res = solution.lengthOfLongestSubstringTwoDistinct(s2);

}
