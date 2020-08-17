// 156-Merge-Intervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

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
     * @param intervals: interval list.
     * @return: A new interval list.
     */

    static bool comp(Interval& a, Interval& b)
    {
        return a.start < b.start;
    }


    vector<Interval> merge(vector<Interval>& intervals) {
        // write your code here

        if (intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end(), comp);

        vector<Interval> merged;

        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            int prev_start = merged.back().start;
            int prev_end = merged.back().end;

            if (prev_end >= intervals[i].start)
            {
                int new_end = intervals[i].end;

                if (prev_end >= intervals[i].end)
                    new_end = prev_end;

                merged.pop_back();
                merged.push_back(Interval(prev_start, new_end));
            }
            else
                merged.push_back(intervals[i]);
        }

        return merged;
    }
};

int main()
{
    vector<Interval> v1{ Interval(1, 4), Interval(0, 2), Interval(3, 5) };

    vector<Interval> v2{ Interval(2,3),Interval(2,2),Interval(3,3),Interval(1,3),Interval(5,7),Interval(2,2),Interval(4,6) };


    Solution solution;

    vector<Interval> res = solution.merge(v2);
}
