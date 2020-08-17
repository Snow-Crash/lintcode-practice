// 486-Merge-K-Sorted-Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
        // write your code here

        vector<int> result = rec(arrays, 0, arrays.size()-1);

        return result;

    }

    vector<int> rec(vector<vector<int>>& arrays, int start, int end)
    {

        if (start >= end)
            return arrays[start];

        int mid = (start + end) / 2;

        vector<int> v1 = rec(arrays, start, mid);
        vector<int> v2 = rec(arrays, mid + 1, end);

        vector<int> merged;

        merge(v1, v2, merged);

        return merged;
    }


    vector<int> merge(vector<int>& v1, vector<int>& v2, vector<int>& merged)
    {
        int i = 0;
        int j = 0;

        //vector<int> result;

        while (i != v1.size() && j != v2.size())
        {
            if (v1[i] < v2[j])
            {
                merged.push_back(v1[i]);
                i++;
            }
            else
            {
                merged.push_back(v2[j]);
                j++;
            }
        }

        if (i == v1.size())
        {
            merged.insert(merged.end(), v2.begin() + j, v2.end());
        }

        if (j == v2.size())
        {
            merged.insert(merged.end(), v1.begin() + i, v1.end());
        }

        return merged;
    }
};

int main()
{

    vector<vector<int>> arrays{ {1, 3, 5, 7}, {2, 4, 6}, {0, 8, 9, 10, 11} };

    Solution solution;

    vector<int> result = solution.mergekSortedArrays(arrays);

    std::cout << "Hello World!\n";
}
