// 819-Most-Common-Word.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> ban;
        unordered_map<string, int> count;

        for (int i = 0; i < banned.size(); i++)
        {
            string str = lower(banned[i]);
            // transform(str.begin(), str.end(),str.begin(), tolower);
            ban.insert(str);
        }

        vector<string>words;

        split(paragraph, words);

        int p = -1;
        int maxCnt = INT_MIN;

        for (int i = 0; i < words.size(); i++)
        {
            if (ban.count(words[i]) == 0)
            {
                count[words[i]]++;

                if (count[words[i]] > maxCnt)
                {
                    maxCnt = count[words[i]];
                    p = i;
                }
            }
        }

        return words[p];
    }

    void split(string& str, vector<string>& vec)
    {
        size_t begin = 0;
        size_t end = 0;

        while (end != string::npos)
        {

            while (isalpha(str[end]))
                end++;

            string word = lower(str.substr(begin, end - begin));

            vec.push_back(word);

            while (isalpha(str[end]) == false)
                end++;

            end = begin;
        }
        



        vec.push_back(lower(str.substr(begin, end- begin)));
    }

    string lower(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (isalpha(str[i]) == false)
                str.erase(i, 1);
            else
                str[i] = tolower(str[i]);
        }

        return str;
    }
};

int main()
{
    string p1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> b1 { "hit" };

    Solution solution;

    string res = solution.mostCommonWord(p1, b1);
}

