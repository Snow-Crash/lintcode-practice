// 978-Basic-Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s: the given expression
     * @return: the result of expression
     */
    int calculate(string& s) {
        // Write your code here

        int res = 0;
        int op = 1;
        stack<int>  st_res;
        stack<int> st_op;

        for (int i = 0; i != s.size(); i++)
        {
            if (s[i] == '(')
            {
                st_op.push(op);
                op = 1;
                st_res.push(res);
                res = 0;
            }
            else if (s[i] == ')')
            {
                op = st_op.top();
                st_op.pop();

                int temp = st_res.top();
                st_res.pop();

                res = temp + op * res;
            }
            else if (s[i] == '+')
            {
                op = 1;
            }
            else if (s[i] == '-')
            {
                op = -1;
            }
            else if (s[i] == ' ')
                continue;
            else //chars are numbers
            {
                int start = i;

                while (i < s.size() && s[i] >= '0' && s[i] <= '9')
                {
                    i++;
                }
                int end = i - 1;

                string str = s.substr(start, end - start + 1);

                int num = stoi(str);

                res = res + op * num;

                i--;
            }
        }

        return res;
    }
};

int main()
{
    string str1 = "1 + 1";

    Solution solution;

    int res = solution.calculate(str1);
}
