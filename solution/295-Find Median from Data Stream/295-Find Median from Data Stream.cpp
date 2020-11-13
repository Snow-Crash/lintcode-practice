// 295-Find Median from Data Stream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */

    priority_queue<int> h1;

    priority_queue<int, vector<int>, greater<int> > h2;


    MedianFinder() {

    }

    void addNum(int num) {

        h1.push(num);
        int val = h1.top();
        h1.pop();
        h2.push(val);

        if (h2.size() > h1.size())
        {

            val = h2.top();
            h1.push(val);
            h2.pop();
        }
    }

    double findMedian() {
        if ((h1.size() + h2.size()) % 2 == 0)
            return (h1.top() + h2.top()) / 2.0;
        else
            return h1.top();

    }
};



int main()
{
    MedianFinder finder;

    finder.addNum(1);
    finder.addNum(2);
    double res = finder.findMedian();
    finder.addNum(3);
    res = finder.findMedian();


    MedianFinder finder2;
    finder2.addNum(-1);
    double res2 = finder2.findMedian();
    finder2.addNum(-2);
    res2 = finder2.findMedian();
    finder2.addNum(-3);
    res2 = finder2.findMedian();
    finder2.addNum(-4);
    res2 = finder2.findMedian();
    finder2.addNum(-5);
    res2 = finder2.findMedian();

}

