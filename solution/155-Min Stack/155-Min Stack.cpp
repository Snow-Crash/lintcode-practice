// 155-Min Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    stack<pair<int, int>> s;
    int minVal = INT_MAX;

    void push(int x) {

        if (x < minVal)
        {
            minVal = x;
        }
        s.push({ x,minVal });
    }

    void pop() {

        if (s.empty() != true)
        {
            s.pop();

            if (s.empty() != true)
            {
                minVal = s.top().second;
            }
            else
                minVal = INT_MAX;
        }
    }

    int top() {

        return s.top().first;
    }

    int getMin() {

        return minVal;
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}