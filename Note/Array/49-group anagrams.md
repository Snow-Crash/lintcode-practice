# 49. Group Anagrams

<https://leetcode.com/problems/group-anagrams/>

## Summary

Sort the string then all the anagrams will be the same. The sorted sting can be used as key. Use a hash table to store results.

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];

            sort(str.begin(), str.end(), comp);

            m[str].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            res.push_back(it->second);
        }

        return res;
    }

    static bool comp(char& a, char& b)
    {
        if (a < b)
            return true;
        else
            return false;
    }
};
```