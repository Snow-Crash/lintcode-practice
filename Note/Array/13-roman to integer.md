# Integer to Roman

<https://leetcode.com/problems/integer-to-roman>

## Solution

```cpp
class Solution {
public:
    int romanToInt(string s) {

        unordered_map<string, int> m{ {"I", 1},
                                    {"IV", 4},
                                    {"V", 5},
                                    {"IX", 9},
                                    {"X", 10},
                                    {"XL", 40},
                                    {"L", 50},
                                    {"XC", 90},
                                    {"C", 100},
                                    {"CD",400},
                                    {"D", 500},
                                    {"CM", 900},
                                    {"M", 1000} };

        int res = 0;

        int i = s.size() - 1;

        while (i >= 0)
        {
            if (i - 1 >= 0 && m.count(s.substr(i - 1, 2)))
            {
                int num = m[s.substr(i - 1, 2)];
                res += num;
                i = i - 2;
            }
            else
            {
                res = res + m[s.substr(i, 1)];
                i--;
            }
        }
        return res;
    }
};
```

## Solution

<https://leetcode.com/problems/roman-to-integer/solution/>