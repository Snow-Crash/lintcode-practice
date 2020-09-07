// 8-_-String-to-Integer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {

        int res = 0;
        vector<int> digits;
        int sign = 1;
        int start = 0;

        int signCnt = 0;

        for (int i = 0; i != str.size(); i++)
        {
            char c = str[i];

            if (digits.size() == 0)
            {
                if (c == ' ')
                    continue;
                else if (c == '+')
                {
                    signCnt++;
                    if (signCnt > 1)
                        return 0;
                }
                else if (c == '-')
                {
                    sign = -1;
                    signCnt++;

                    if (signCnt > 1)
                        return 0;
                }
                else if (isdigit(c))
                {
                    if (c - '0' != 0)
                        digits.push_back(c - '0');
                }
                else
                    break;
            }
            else
            {
                if (isdigit(c))
                    digits.push_back(c - '0');
                else
                    break;
            }
        }

        reverse(digits.begin(), digits.end());

        int base = 1;

        int cnt = INT_MAX;

        int overflow = 0;

        for (int i = 0; i != digits.size(); i++)
        {
            int temp = base * digits[i];
            cnt -= temp;

            if (cnt < 0)
            {
                overflow = 1;
                break;
            }

            if (INT_MAX / 10 < base)
            {
                overflow = 1;
                break;
            }

            base = base * 10;
            res = res + temp;
        }

        if (overflow)
        {
            if (sign == -1)
                return INT_MIN;
            else
                return INT_MAX;
        }

        return res * sign;
    }
};

int main()
{
    string s1 = "  0000000000012345678";
    string s2 = "words and 987";
    string s3 = "+-2";

    Solution solution;

    int res = solution.myAtoi(s3);

}
