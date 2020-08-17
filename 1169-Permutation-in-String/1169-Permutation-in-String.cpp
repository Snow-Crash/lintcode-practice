// 1169-Permutation-in-String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @param s1: a string
     * @param s2: a string
     * @return: if s2 contains the permutation of s1
     */
    bool checkInclusion(string& s1, string& s2) {
        // write your code here

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (int i = 0; i != s1.size(); i++)
        {
            m1[s1[i]]++;
        }

        int l = 0;
        int r = 0;

        int k = s1.size();

        int valid = 0;

        for (; r != s2.size(); r++)
        {
            char c = s2[r];
            m2[c] ++;

            if (m1.count(c) > 0)
            {
                if (m2[c] == m1[c])
                    valid++;
            }

            if (r - l + 1 == k)
            {
                if (valid == m1.size())
                    return true;

                char lc = s2[r + 1 - k];
                if (m1.count(lc) > 0)
                    if (m1[lc] == m2[lc])
                        valid--;

                m2[lc]--;

                l++;
            }
        }
        return false;
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "eidboaoo";

    string s3 = "qfkzizwqb";
    string s4 = "ksdwkyeqhetoanqfkizzwqb";
    
    Solution solution;

    bool result = solution.checkInclusion(s3, s4);
}
