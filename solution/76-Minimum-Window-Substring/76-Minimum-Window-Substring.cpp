// 76-Minimum-Window-Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> m;

        unordered_map<char, int> count;

        for (int i = 0; i < t.size(); i++)
            m[t[i]] ++;

        int valid = 0;

        int minWindow = INT_MAX;

        int l = 0;
        int r = 0;

        int left = 0;
        int right = 0;

        while (r < s.size())
        {
            char c = s[r];
            count[c]++;

            if (m.count(c) > 0)
            {
                if (count[c] == m[c])
                    valid++;
            }

            // reduce window while guarantee that it contains desired chars
            while (valid == m.size())
            {
                if (r - l + 1 < minWindow)
                {
                    left = l;
                    right = r;
                    minWindow = r - l + 1;
                }

                // 
                char discard = s[l];
                l++;

                // if the char discarded by moving l to right appears in t
                if (m.count(discard) > 0)
                {
                    //the window used to contain qualified char,
                    //but now, one char is out of the window, so valid decrease by 1
                    if (count[discard] == m[discard])
                        valid--;
                    count[discard] --;
                }
            }
            r++;
        }

        if (minWindow == INT_MAX)
            return "";
        return
            s.substr(left, right - left + 1);
    }
};

int main()
{

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";

    string s2 = "a";
    string t2 = "aa";

    string s3 = "ab";
    string t3 = "a";

    string s4 = "aa";
    string t4 = "aa";

    Solution solution;

    string res = solution.minWindow(s4, t4);

}