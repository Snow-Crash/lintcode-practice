// 28-Implement-strStr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (haystack.size() == 0 && needle.size() == 0)
            return 0;

        int m = haystack.size();
        int n = needle.size();

        for (int i = 0; i <= m-n; i++)
        {

            int j = 0;

            while (j < needle.size() && i + j < haystack.size())
            {
                if (needle[j] == haystack[i + j])
                    j++;
                else
                    break;
            }

            if (j == needle.size())
                return i;
        }

        return -1;

    }
};

int main()
{
    string s1 = "hello";
    string s2 = "ll";

    string s3 = "";
    string s4 = "a";

    string s5 = "a";
    string s6 = "a";

    Solution solution;

    int res = solution.strStr(s5, s6);

}
