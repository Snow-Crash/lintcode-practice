// 322-coin change.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int coin = coins[j];
                int rest = i - coin;
                if (rest < 0)
                    continue;
                dp[i] = min(dp[i], dp[rest] + 1);
            }
        }

        return dp.back() == amount + 1 ? -1 : dp.back();
    }
};

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int val = 0; val <= amount; val++)
        {
            for (int i = 0; i < coins.size(); i++)
            {
                int coin = coins[i];
                int rest = val - coin;

                if (rest < 0)
                    continue;

                dp[val] = min(dp[val], dp[rest] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main()
{
    vector<int> v1{ 1,2,5 };

    vector<int> v2{ 1 };

    Solution2 solution;

    int res = solution.coinChange(v2, 0);
}