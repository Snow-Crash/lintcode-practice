// 58-4sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int>& numbers, int target) {
        // write your code here

        set<vector<int>>res;

        vector<vector<int>> result;

        quicksort(numbers, 0, numbers.size() - 1);

        vector<int> path;

        int size = numbers.size();

        for (int i = 0; i < size - 3; i++)
        {
            for (int j = i + 1; j != numbers.size() - 2; j++)
            {
                if (j > i + 1 && numbers[j] == numbers[j - 1])
                    continue;

                int l = j + 1;
                int r = numbers.size() - 1;

                while (l != r)
                {
                    int sum = numbers[i] + numbers[j] + numbers[l] + numbers[r];

                    if (sum == target)
                        res.insert(vector<int>{numbers[i], numbers[j], numbers[l], numbers[r]});
                    else if (sum < target)
                        l++;
                    else
                        r--;

                }
            }
        }

        // for (int i = 0; i != numbers.size(); i++)
        // {
        //     path.push_back(numbers[i]);
        //     dfs(numbers, res, path, i + 1, numbers[i], target);
        //     path.pop_back();
        // }

        for (auto it = res.begin(); it != res.end(); it++)
        {
            result.push_back(*it);
        }

        return result;
    }

    void quicksort(vector<int>& numbers, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = numbers[left];

        int i = left + 1;
        int j = right;

        while (i <= j)
        {
            if (numbers[i] > pivot && numbers[j] < pivot)
                swap(numbers[i], numbers[j]);

            if (numbers[i] <= pivot)
                i++;

            if (numbers[j] >= pivot)
                j--;
        }

        swap(numbers[left], numbers[j]);

        quicksort(numbers, left, j - 1);
        quicksort(numbers, j + 1, right);
    }


    void dfs(vector<int>& numbers, set<vector<int>>& res, vector<int>& path, int idx, int sum, int target)
    {
        if (path.size() == 4)
        {
            if (sum == target)
                res.insert(path);

            return;
        }

        if (idx >= numbers.size())
            return;

        if (sum >= target && numbers[idx] > 0)
            return;

        if (idx + 4 - path.size() > numbers.size())
            return;


        for (int i = idx; i != numbers.size(); i++)
        {

            int new_sum = sum + numbers[i];

            if (new_sum > target && numbers[i] > 0)
                break;

            if (numbers.size() == 1)
            {
                if (i > idx && numbers[i] == numbers[i - 1])
                    continue;
            }

            path.push_back(numbers[i]);
            dfs(numbers, res, path, i + 1, new_sum, target);

            path.pop_back();
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";

    vector<int> numbers{ 2,7,11,15 };

    vector<int> numbers2{ 1, 0, -1, 0, -2, 2 };

    vector<int> numbers3{ 1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,0,0,-2,2,-5,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99,1,2,5,6,7,3,5,8,-33,-5,-72,12,-34,100,99 };

    vector<int> numbers4{ 1,0,-1,0,-2,2 };

    Solution solution;

    vector<vector<int>> result = solution.fourSum(numbers4, -2);

}
