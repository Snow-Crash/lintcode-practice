// 91-Decode Ways.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {

        if (s.size() == 0)
            return 0;

        vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;


        for (int i = 2; i < dp.size(); i++)
        {
            if (s[i - 1] != '0')
                dp[i] = dp[i - 1];

            if (s[i - 2] != '0' && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }

        return dp.back();

    }
};

int main()
{
    Solution solution;

    string s1 = "226";

    int res = solution.numDecodings(s1);
}
