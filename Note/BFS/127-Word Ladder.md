# 127. Word Ladder

<https://leetcode.com/problems/word-ladder/>

## Summary

BFS. Use a queue and first push beginWord into queue. Use a hast set to store all words in wordList. And a had table to record visited word. For every word from queue, change every character from a to z, and check if the new word is in the hash set. If it is in the hash set and not visited, put into queue and mark as visited.

## Solution 1

BFS

```cpp
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
```

## Solution 2

DFS, not recommended

```cpp
class Solution {
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
```

## Reference

<https://www.cnblogs.com/grandyang/p/4539768.html>