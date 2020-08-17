// 421- Simplify-Path.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/simplify-path/description

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string& path) {
        // write your code here

        stack<string> s;

        for (int i = 0; i < path.size(); i++)
        {
            while (path[i] == '/' && i < path.size())
                i++;
            if (i == path.size())
                break;

            int start = i;

            while (path[i] != '/' && i < path.size())
                i++;

            int end = i - 1;

            string str = path.substr(start, end - start + 1);

            if (str == "..")
            {
                if (s.empty() == false)
                    s.pop();
            }
            else if (str != ".")
                s.push(str);
        }

        if (s.empty() == true)
            return "/";

        string result = "";

        while (s.empty() == false)
        {
            result = "/" + s.top() + result;
            s.pop();
        }

        return result;
    }
};

int main()
{
    string p1 = "/home/";
    string p2 = "/.";
    string p3 = "/..";

    Solution solution;

    string res = solution.simplifyPath(p3);
}