// 29-Interleaving-String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <unordered_set>

class Solution1 {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string& s1, string& s2, string& s3) {
        // write your code here

        return dfs(s1, s2, s3, 0, 0, 0);

    }

    bool dfs(string& s1, string& s2, string& s3, int k1, int k2, int k3)
    {
        if (k1 == s1.size() && s2.substr(k2) == s3.substr(k1 + k2))
            return true;

        if (k2 == s2.size() && s1.substr(k1) == s3.substr(k1 + k2))
            return true;

        if ((s1[k1] == s3[k1 + k2] && dfs(s1, s2, s3, k1 + 1, k2, k3+1)) ||
            (s2[k2] == s3[k1 + k2] && dfs(s1, s2, s3, k1, k2 + 1, k3+1)))
        {
            return true;
        }


        return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        unordered_set<int> s;
        return helper(s1, 0, s2, 0, s3, 0, s);
    }
    bool helper(string& s1, int i, string& s2, int j, string& s3, int k, unordered_set<int>& s) {
        int key = i * s3.size() + j;
        if (s.count(key)) 
            return false;

        if (i == s1.size()) 
            return s2.substr(j) == s3.substr(k);

        if (j == s2.size()) 
            return s1.substr(i) == s3.substr(k);

        if ((s1[i] == s3[k] && helper(s1, i + 1, s2, j, s3, k + 1, s)) ||
            (s2[j] == s3[k] && helper(s1, i, s2, j + 1, s3, k + 1, s))) 
            return true;

        s.insert(key);
        return false;
    }
};

int main()
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    Solution1 solution;

    //Solution solution;
    
    bool result = solution.isInterleave(s1, s2, s3);
}