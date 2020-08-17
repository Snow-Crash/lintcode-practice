// 363-Trapping-Rain-Water.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int>& heights) {
        // write your code here

        int i = 0;

        int acc = 0;
        while (i < heights.size())
        {
            int h = heights[i];
            int j = i + 1;

            int temp_acc = 0;
            while (j < heights.size() && heights[j] < h)
            {
                temp_acc = temp_acc + heights[i] - heights[j];
                j++;
            }

            if (j != heights.size())
                acc = acc + temp_acc;

            i = j;
        }

        i = heights.size() - 1;
        while (i > 0)
        {
            int h = heights[i];
            int j = i - 1;

            int temp_acc = 0;
            while (j > 0 && heights[j] <= h)
            {
                temp_acc = temp_acc + heights[i] - heights[j];
                j--;
            }

            if (j != 0)
                acc = acc + temp_acc;

            i = j;
        }

        return acc;
    }
};

int main()
{
    vector<int> v1{ 0,1,0,2,1,0,1,3,2,1,2,1 };

    vector<int> v2{ 100,50,99,50,100,50,99,50,100,50 };

    Solution solution;

    int result = solution.trapRainWater(v2);
}
