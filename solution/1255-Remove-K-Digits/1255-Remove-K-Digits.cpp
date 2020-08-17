// 1255-Remove-K-Digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param num: a string
     * @param k: an integer
     * @return: return a string
     */
    string removeKdigits(string& num, int k) {
        // write your code here

        string result = "";

        int left_size = num.size() - k;

        for (int i = 0; i < num.size(); i++)
        {
            while (k > 0 && result.size() > 0 && result.back() > num[i])
            {
                result.pop_back();
                k--;
            }

            result.push_back(num[i]);
        }

        int i = 0;
        while (i < result.size() && result[i] == '0')
            i++;

        result = result.substr(i);

        if (result.size() == 0)
            return "0";

        if (result.size() > left_size)
            return result.substr(result.size() - left_size);

        return result;
    }
};

int main()
{
    Solution solution;

    string n1 = "1432219";

    string result = solution.removeKdigits(n1, 3);
}
