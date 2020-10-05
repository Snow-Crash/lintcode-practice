# Implement Strstr

## Summary

## Solution

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {

        if (haystack.size() == 0 && needle.size() == 0)
            return 0;

        int m = haystack.size();
        int n = needle.size();

        for (int i = 0; i <= m-n; i++)
        {

            int j = 0;

            while (j < needle.size() && i + j < haystack.size())
            {
                if (needle[j] == haystack[i + j])
                    j++;
                else
                    break;
            }

            if (j == needle.size())
                return i;
        }

        return -1;

    }
};
```

## Reference

<https://www.cnblogs.com/grandyang/p/4606696.html>