// 259-3Sum-Smaller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
                break;
            else
            {
                if (i == 0 || nums[i] != nums[i - 1])
                    twosum(nums, target, i, cnt);
            }
        }
        return cnt;

    }

    void twosum(vector<int>& nums, int target, int idx, int& cnt)
    {
        int i = idx + 1;
        int j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[idx] + nums[i] + nums[j];

            if (sum < target)
            {
                cnt++;
                j--;
                while (j > i && nums[j-1] == nums[j])
                    j--;
            }
            else
            {
                j--;
            }
        }
    }
};

int main()
{
    vector<int> v1{ -2 ,0,1,3 };

    Solution solution;

    int res1 = solution.threeSumSmaller(v1, 2);
}
