// 32-Minimum-Window-Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/solution/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string& source, string& target) {
        // write your code here

        unordered_map<char, int> target_map;

        unordered_map<char, int> m;

        for (int i = 0; i != target.size(); i++)
        {
            target_map[target[i]] ++;
        }


        int left = 0;
        int right = 0;

        int window_start = 0;

        int minLen = INT_MAX;

        int valid = 0;

        for (; right < source.size(); right++)
        {

            char current = source[right];

            m[current] ++;

            //if current char in target
            if (target_map.count(current) > 0)
            {
                if (m[current] == target_map[current])
                    valid++;
            }

            while (valid == target_map.size())
            {
                if (right - left + 1 < minLen)
                {
                    window_start = left;
                    minLen = right - left + 1;
                }

                int c = source[left];
                left++;

                if (target_map.count(c) > 0)
                {
                    if (target_map[c] == m[c])
                        valid--;
                    m[c] --;
                }
            }
        }

        if (minLen == INT_MAX)
            return "";
        else
            return source.substr(window_start, minLen);
    }



};

int main()
{
    string s1 = "abc";
    string t1 = "ac";

    string s2 = "absdfaabab";
    string t2 = "adb";

    string s3 = "abcdecf";
    string t3 = "acc";


    Solution solution;

    string result = solution.minWindow(s3, t3);
}
