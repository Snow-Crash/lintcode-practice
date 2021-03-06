// 165-compare-version-numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<int> s1 = split(version1, '.');
        vector<int> s2 = split(version2, '.');

        int i = 0;
        int j = 0;

        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] < s2[j])
                return -1;
            else if (s1[i] > s2[j])
                return 1;

            i++;
            j++;
        }

        if (i == s1.size() && j == s2.size())
            return 0;
        
        if (i == s1.size())
        {
            while (j < s2.size())
            {
                if (s2[j] > 0)
                    return -1;
                j++;
            }

            return 0;
        }
        else
        {
            while (i < s1.size())
            {
                if (s1[i] > 0)
                    return 1;
                i++;
            }

            return 0;
        }  
    }

    vector<int> split(string& str, char delim)
    {
        size_t start = 0;
        size_t end = str.find('.');

        vector<int> splitted;

        while (end != string::npos)
        {
            string substr = str.substr(start, end - start);

            size_t non_zero = substr.find_first_not_of('0');

            if (non_zero != string::npos)
                splitted.push_back(stoi(substr.substr(non_zero)));
            splitted.push_back(0);

            start = end + 1;
            end = str.find(delim, start);
        };


        string substr = str.substr(start, end);

        size_t non_zero = substr.find_first_not_of('0');

        if (non_zero != string::npos)
            splitted.push_back(stoi(substr.substr(non_zero)));
        else
            splitted.push_back(0);

        return splitted;
    }
};

int main()
{
    string s1 = "0.1";
    string s2 = "1.1";

    string s3 = "1.0";
    string s4 = "1";

    Solution solution;

    int res = solution.compareVersion(s3, s4);

}