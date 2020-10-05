// 238-Product-of Array-Except-Self.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(left[i] * right[i]);
        }

        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
