// 20-Valid-Parentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (st.empty() == true)
            {
                st.push(c);
            }
            else
            {
                if (st.top() == '[')
                {
                    if (c == ']')
                        st.pop();
                    else if (c == '(' || c == '{' || c == '[')
                        st.push(c);
                    else
                        return false;
                }
                else if (st.top() == '(')
                {
                    if (c == ')')
                        st.pop();
                    else if (c == '[' || c == '{' || c == '(')
                        st.push(c);
                    else
                        return false;
                }
                else if (st.top() == '{')
                {
                    if (c == '}')
                        st.pop();
                    else if (c == '[' || c == '(' || c == '{')
                        st.push(c);
                    else
                        return false;
                }
            }
        }

        if (st.empty() == true)
            return true;

        return false;
    }
};

int main()
{
    string s1 = "(([]){})";
    
    Solution solution;

    bool res = solution.isValid(s1);
}