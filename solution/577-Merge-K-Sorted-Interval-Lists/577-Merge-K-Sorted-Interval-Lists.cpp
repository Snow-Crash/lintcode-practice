// 577-Merge-K-Sorted-Interval-Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


class Solution {
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>>& intervals) {
        // write your code here


        vector<Interval> merged = recursion(intervals, 0, intervals.size() - 1);

        vector<Interval> result;

        if (merged.size() > 0)
            result.push_back(merged[0]);

        int i = 1;

        while (i < merged.size())
        {
            if (result.back().end >= merged[i].start)
            {
                int new_start = result.back().start;

                int new_end = result.back().end > merged[i].end ? result.back().end : merged[i].end;

                result.pop_back();

                result.push_back(Interval(new_start, new_end));
            }
            else
                result.push_back(merged[i]);

            i++;
        }

        return result;
    }

    vector<Interval> recursion(vector<vector<Interval>>& intervals, int begin, int end)
    {
        if (begin >= end)
            return intervals[begin];

        int mid = (begin + end) / 2;

        vector<Interval> v1 = recursion(intervals, begin, mid);

        vector<Interval> v2 = recursion(intervals, mid + 1, end);

        vector<Interval> merged;

        merge(v1, v2, merged);

        return merged;
    }

    void merge(vector<Interval>& v1, vector<Interval>& v2, vector<Interval>& merged)
    {
        int i = 0;
        int j = 0;

        while (i < v1.size() && j < v2.size())
        {
            if (v1[i].start < v2[j].start)
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
            merged.insert(merged.end(), v1.begin() + i, v1.end());
    }
};

int main()
{
    
    vector<vector<Interval>> v1{ {Interval(1,3), Interval(4,7), Interval(6,8)},
        {Interval(1,2), Interval(9,10)} };

    vector<vector<Interval>> v2 { { Interval(2, 5), Interval(9, 13), Interval(16, 28), Interval(32, 53) },
                                    { Interval(1, 3), Interval(16, 17), Interval(22, 27), Interval(47, 51) },
                                    { Interval(16, 22), Interval(31, 50), Interval(51, 53), Interval(57, 61) },
                                    { Interval(1, 9), Interval(17, 20), Interval(23, 25), Interval(27, 34) },
                                    { Interval(4, 11), Interval(14, 18), Interval(19, 21), Interval(28, 35) } };

    Solution solution;

    vector <Interval> result = solution.mergeKSortedIntervalLists(v2);

}