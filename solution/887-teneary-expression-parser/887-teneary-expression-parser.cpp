// 887-teneary-expression-parser.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/ternary-expression-parser/description
// ref: https://www.cnblogs.com/grandyang/p/6022498.html

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param expression: a string, denote the ternary expression
     * @return: a string
     */
    string parseTernary(string& expression) {
        // write your code here

        stack<char> s;

        for (int i = expression.size() - 1; i >= 0; i--)
        {
            char c = expression[i];

            if (s.empty() == false && s.top() == '?')
            {
                s.pop();
                char first = s.top();
                s.pop();
                s.pop();
                char second = s.top();
                s.pop();

                if (c == 'T')
                    s.push(first);
                else
                    s.push(second);
            }
            else
            {
                s.push(c);
            }
        }

        return string(1, s.top());
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
