// 575-Decode-String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string& s) {
        // write your code here

        stack<int> st_num;
        stack<string> st_str;

        int num = 0;
        string str = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
            {
                int nun_start = i;
                while (s[i] != '[')
                    i++;

                int num_end = i - 1;

                string num_str = s.substr(nun_start, num_end - nun_start + 1);
                num = stoi(num_str);

                //st_num.push(num);

                i--;
            }
            else if (s[i] == '[')
            {
                st_str.push(str);
                st_num.push(num);
                str = "";
            }
            else if (s[i] == ']')
            {
                num = st_num.top();
                st_num.pop();

                string temp = st_str.top();

                for (int i = 0; i < num; i++)
                {
                    temp += str;
                }

                str = temp;

                st_str.pop();
            }
            else
            {
                int str_start = i;
                while (i < s.size() && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
                    i++;

                int str_end = i - 1;

                str = str + s.substr(str_start, str_end - str_start+1);

                i--;
            }
        }

        if (st_str.empty() == false)
            return st_str.top();
        else
            return str;
    }
};

int main()
{
    Solution solution;

    string str = "abc3[a]";

    string str2 = "3[2[ad]3[pf]]xyz";

    string res = solution.expressionExpand(str2);
}