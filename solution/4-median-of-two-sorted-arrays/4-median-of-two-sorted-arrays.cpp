// 4-median-of-two-sorted-arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int p1 = 0;
        int p2 = 0;

        int p = 0;

        vector<int> merge;

        while (p <= (m + n) / 2)
        {
            if (p1 < m && p2 < n)
            {
                if (nums1[p1] <= nums2[p2])
                {
                    merge.push_back(nums1[p1]);
                    p1++;
                }

                else
                {
                    merge.push_back(nums2[p2]);
                    p2++;
                }
            }
            else if (p1 >= m)
            {
                merge.push_back(nums2[p2]);
                p2++;
            }
            else if (p2 >= n)
            {
                merge.push_back(nums1[p1]);
                p1++;
            }
            p++;
        }

        if ((m + n) % 2 == 0)
            return ((double)(merge.back() + merge[merge.size() - 2]) / 2);
        else
            return merge.back();

    }
};

int main()
{
    vector<int> v1{ 1,2 };
    vector<int> v2{ 3,4 };

    Solution solution;

    double res = solution.findMedianSortedArrays(v1, v2);
}
