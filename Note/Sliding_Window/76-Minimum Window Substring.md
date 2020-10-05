# 76. Minimum Window Substring

## Summary

Use a hash table T1 to count the occurrence of each char in t. And second hash table T2 to count the occurrence of each character in window. Use a variable 'valid' to record how many characters occurrence in current window is the same as t. When shrink the window, if the character go out of window appears in T1, valid should be decreased by 1, because this character's occurrence is the same as in t, but now it is moved out of window.

## Solution 1

```cpp
class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> m;

        unordered_map<char, int> count;

        for (int i = 0; i < t.size(); i++)
            m[t[i]] ++;

        int valid = 0;

        int minWindow = INT_MAX;

        int l = 0;
        int r = 0;

        int left = 0;
        int right = 0;

        while (r < s.size())
        {
            char c = s[r];
            count[c]++;

            if (m.count(c) > 0)
            {
                if (count[c] == m[c])
                    valid++;
            }

            // reduce window while guarantee that it contains desired chars
            while (valid == m.size())
            {
                if (r - l + 1 < minWindow)
                {
                    left = l;
                    right = r;
                    minWindow = r - l + 1;
                }

                char discard = s[l];
                l++;

                // if the char discarded by moving l to right appears in t
                if (m.count(discard) > 0)
                {
                    //the window used to contain qualified char,
                    //but now, one char is out of the window, so valid decrease by 1
                    if (count[discard] == m[discard])
                        valid--;
                    count[discard] --;
                }
            }
            r++;
        }

        if (minWindow == INT_MAX)
            return "";
        return
            s.substr(left, right - left + 1);
    }
};

## Solution2

<https://www.cnblogs.com/grandyang/p/4340948.html>

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) ++letterCnt[c];
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
};
```

## Solution 3

<https://leetcode.com/problems/minimum-window-substring/solution/>

```java
class Solution {
  public String minWindow(String s, String t) {

      if (s.length() == 0 || t.length() == 0) {
          return "";
      }

      // Dictionary which keeps a count of all the unique characters in t.
      Map<Character, Integer> dictT = new HashMap<Character, Integer>();
      for (int i = 0; i < t.length(); i++) {
          int count = dictT.getOrDefault(t.charAt(i), 0);
          dictT.put(t.charAt(i), count + 1);
      }

      // Number of unique characters in t, which need to be present in the desired window.
      int required = dictT.size();

      // Left and Right pointer
      int l = 0, r = 0;

      // formed is used to keep track of how many unique characters in t
      // are present in the current window in its desired frequency.
      // e.g. if t is "AABC" then the window must have two A's, one B and one C.
      // Thus formed would be = 3 when all these conditions are met.
      int formed = 0;

      // Dictionary which keeps a count of all the unique characters in the current window.
      Map<Character, Integer> windowCounts = new HashMap<Character, Integer>();

      // ans list of the form (window length, left, right)
      int[] ans = {-1, 0, 0};

      while (r < s.length()) {
          // Add one character from the right to the window
          char c = s.charAt(r);
          int count = windowCounts.getOrDefault(c, 0);
          windowCounts.put(c, count + 1);

          // If the frequency of the current character added equals to the
          // desired count in t then increment the formed count by 1.
          if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
              formed++;
          }

          // Try and contract the window till the point where it ceases to be 'desirable'.
          while (l <= r && formed == required) {
              c = s.charAt(l);
              // Save the smallest window until now.
              if (ans[0] == -1 || r - l + 1 < ans[0]) {
                  ans[0] = r - l + 1;
                  ans[1] = l;
                  ans[2] = r;
              }

              // The character at the position pointed by the
              // `Left` pointer is no longer a part of the window.
              windowCounts.put(c, windowCounts.get(c) - 1);
              if (dictT.containsKey(c) && windowCounts.get(c).intValue() < dictT.get(c).intValue()) {
                  formed--;
              }

              // Move the left pointer ahead, this would help to look for a new window.
              l++;
          }

          // Keep expanding the window once we are done contracting.
          r++;
      }

      return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
  }
}
```