// 15-permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/permutations/description
// ref: https://www.cnblogs.com/grandyang/p/4358848.html

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int>& nums) {
        // write your code here

        vector<int> permute;
        vector<int> visited(nums.size(), 0);

        vector<vector<int> > result;

        dfs(result, nums, permute, visited);

        return result;


    }

    void dfs(vector<vector<int> >& result, vector<int>& nums, vector<int>& permute, vector<int>& visited)
    {
        if (permute.size() < nums.size())
        {
            for (int i = 0; i != nums.size(); i++)
            {
                if (visited[i] != 1)
                {
                    vector<int> temp_visited = visited;
                    vector<int> temp_permute = permute;

                    temp_permute.push_back(nums[i]);
                    temp_visited[i] = 1;

                    dfs(result, nums, temp_permute, temp_visited);
                }
            }
        }
        else
        {
            result.push_back(permute);
        }
    }

};

int main()
{
    std::cout << "Hello World!\n";
}