// 127-Word-Ladder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string> q;
        unordered_map<string, int> visited;
        q.push(beginWord);

        int length = 0;

        while (q.empty() == false)
        {
            length++;

            int q_size = q.size();

            for (int i = 0; i < q_size; i++)
            {
                string current = q.front();
                q.pop();

                if (current == endWord)
                    return length;

                for (int j = 0; j < beginWord.size(); j++)
                {
                    string word = current;

                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[j] = c;

                        if (dict.count(word) > 0 && visited[word] == 0)
                        {
                            visited[word] = 1;
                            q.push(word);
                        }
                    }
                }
            }
        }
        return 0;
    }
};


class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string, unordered_map<string, int>> dist;

        queue<string> q;
        unordered_map<string, int> visited;
        q.push(beginWord);

        int length = 0;

        while (q.empty() == false)
        {
            length++;

            int q_size = q.size();

            for (int j = 0; j < q_size; j++)
            {
                string current = q.front();
                q.pop();

                if (current == endWord)
                    return length;

                for (int i = 0; i < wordList.size(); i++)
                {
                    if (visited[wordList[i]] == 0)
                    {
                        int d = dist[current][wordList[i]];

                        if (d == 0)
                        {
                            d = diff(current, wordList[i]);
                            dist[current][wordList[i]] = d;
                            dist[wordList[i]][current] = d;
                        }

                        if (d == 1)
                        {
                            visited[wordList[i]] = 1;
                            q.push(wordList[i]);
                        }
                    }
                }
            }
        }

        return 0;
    }

    int diff(string& s1, string& s2)
    {
        int d = 0;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                d++;
        }

        return d;
    }
};

int main()
{
    Solution solution;

    vector<string> list{ "hot","dot","dog","lot","log","cog" };
    vector<string> list2{ "hot","dot","dog","lot","log" };
    string begin = "hit";
    string end = "cog";

    int res = solution.ladderLength(begin, end, list2);
}
