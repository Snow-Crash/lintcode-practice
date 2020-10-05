# 167. Two Sum II - Input array is sorted

<https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/>


## Summary

## Solutions

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        unordered_set<int> s{numbers.begin(), numbers.end()};
        
        unordered_map<int, pair<int,int>> m;
        
        for(int i = 0; i < numbers.size(); i++)
        {
            if (m.count(numbers[i]) > 0)
                return {m[numbers[i]].second+1 ,i+1};
            
            int remain = target - numbers[i];
            
            m[remain] = {numbers[i], i};
        }
        
        return {};
    }
};
```