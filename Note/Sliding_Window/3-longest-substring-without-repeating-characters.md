# Longest Substring Without Repeating Characters

<https://leetcode.com/problems/longest-substring-without-repeating-characters>
<https://www.lintcode.com/problem/longest-substring-without-repeating-characters/description>

## Key points

Use sliding window. A hashtable tracks the occurrence of each character.

## Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 0)
            return 0;

        int left = 0;
        int right = 0;

        int begin = 0;
        int end = 0;

        int maxLen = INT_MIN;

        unordered_map<char, int> count;

        for (; right < s.size(); right++)
        {
            char c = s[right];

            count[c]++;

            if (count[c] == 1)
            {
                if (right - left + 1 > maxLen)
                {
                    maxLen = right - left + 1;
                    begin = left;
                    end = right;
                }
            }
            else
            {
                while (count[c] > 1)
                {
                    count[s[left]]--;
                    left++;
                }
            }
        }
        return maxLen;
    }
};
```

# Reference
https://www.cnblogs.com/grandyang/p/4480780.html
