# Integer to Roman

<https://leetcode.com/problems/integer-to-roman/>

<https://www.lintcode.com/problem/integer-to-roman/description>

## Solution 1

```cpp
class Solution {
public:
    string intToRoman(int num) {

        unordered_map<int, string> m{ {1, "I"},
                                      {2, "II"},
                                      {3, "III"},
                                      {4, "IV"},
                                      {5, "V"},
                                      {6, "VI"},
                                      {7, "VII"},
                                      {8, "VIII"},
                                      {9, "IX"},
                                      {0, ""} };

        unordered_map<int, string> imap{ {1, "I"}, {10, "X"}, {100, "C"}, {1000, "M"} };
        unordered_map<int, string> vmap{ {1, "V"}, {10, "L"}, {100, "D"} };
        unordered_map<int, string> xmap{ {1, "X"}, {10, "C"}, {100, "M"} };

        vector<int> digits;

        int n = num;

        while (n > 0)
        {
            digits.push_back(n % 10);
            n = n / 10;
        }

        string res = "";

        int base = 1;

        for (int i = 0; i < digits.size(); i++)
        {
            string roman = m[digits[i]];

            for (int j = 0; j < roman.size(); j++)
            {
                if (roman[j] == 'I')
                    roman.replace(j, 1, imap[base]);
                else if (roman[j] == 'V')
                    roman.replace(j, 1, vmap[base]);
                else if (roman[j] == 'X')
                    roman.replace(j, 1, xmap[base]);
            }
            res = roman + res;

            base = base * 10;
        }
        return res;
    }
};
```

## Solution 2

```java
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
```

## Reference

<https://leetcode.com/problems/integer-to-roman/discuss/6274/Simple-Solution>

<https://leetcode.com/problems/integer-to-roman/solution/>
