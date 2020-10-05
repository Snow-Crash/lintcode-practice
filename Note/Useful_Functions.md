# Useful Functions

## reverse()

Header: algorithm

## isdigit()

## isalpha

```cpp
// Checks whether c is an alphabetic letter.
int isalpha ( int c );
```

Check if character is alphabetic

## min() and max()

Header: algorithm

## Change sort() order

sort() default order is non-descending. To change to descending order:

```cpp
std::sort(s.begin(), s.end(), std::greater<int>());
```

## Custom Sort Function

```cpp
class Solution {
public:

    int findLUSlength(vector<string>& strs) {

        sort(strs.begin(), strs.end(), comp);

        return -1;
    }

    static bool comp(string& str1, string& str2)
    {
        return str1.size() > str2.size();
    }
};
```

## custom priority queue

```cpp
struct comp
{
    bool operator() (vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            if (a[1] == b[1])
                return a[2] > b[2];
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
};

priority_queue<vector<int>, vector<vector<int>>, comp> q;
```

## Min heap

priority_queue is max heap by default, to make it a min heap

```cpp
priority_queue<int,vector<int>,greater<int> >pq;
```

## Split String

Reference:
<https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c>

```cpp
vector<int> split;
size_t start = 0;
size_t end = s.find(delim);
while (end != std::string::npos)
{
    split.push_back(s.substr(start, end - start));
    start = end + delim.length();
    end = s.find(delim, start);
}

split.push_back(s.substr(start, end));
```

## Remove leading 0

Reference:
<https://stackoverflow.com/questions/25726531/how-to-remove-leading-zeros-from-string-using-c>

```c++

str.erase(0, min(str.find_first_not_of('0'), str.size()-1));

// find_first_not_of(c) returns the position of first char that is not c
// if c not found, it returns string::npos
size_t non_zero = substr.find_first_not_of('0');
```

## int - string convert

```cpp
#include string

int a = stoi(s);

string s= to_string(int);

```
