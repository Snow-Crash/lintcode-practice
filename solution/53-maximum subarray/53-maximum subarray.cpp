// 53-maximum subarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];

        int maxSum = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);

            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            currSum = max(currSum + nums[i], nums[i]);

            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    
}
