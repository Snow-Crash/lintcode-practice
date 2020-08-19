// 13-418-integer-to-roman.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/integer-to-roman
// https://www.lintcode.com/problem/integer-to-roman/description

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        unordered_map<int, string> m{ {1, "I"},
                                      {2, "II"},
                                      {3, "III"},
                                      {4, "IV"},
                                      {5, "V"},
                                      {6, "VI"},
                                      {7, "VII"},
                                      {8, "VIII"},
                                      {9, "IX"},
                                      {0, ""} };

        unordered_map<int, string> imap{ {1, "I"}, {10, "X"}, {100, "C"}, {1000, "M"} };
        unordered_map<int, string> vmap{ {1, "V"}, {10, "L"}, {100, "D"} };
        unordered_map<int, string> xmap{ {1, "X"}, {10, "C"}, {100, "M"} };

        vector<int> digits;

        int n = num;

        while (n > 0)
        {
            digits.push_back(n % 10);
            n = n / 10;
        }

        string res = "";

        int base = 1;

        for (int i = 0; i < digits.size(); i++)
        {
            string roman = m[digits[i]];

            for (int j = 0; j < roman.size(); j++)
            {
                if (roman[j] == 'I')
                    roman.replace(j, 1, imap[base]);
                else if (roman[j] == 'V')
                    roman.replace(j, 1, vmap[base]);
                else if (roman[j] == 'X')
                    roman.replace(j, 1, xmap[base]);
            }
            res = roman + res;

            base = base * 10;
        }
        return res;
    }
};

int main()
{
    Solution solution;

    string res = solution.intToRoman(58);

    string res2 = solution.intToRoman(4);
}
