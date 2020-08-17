// 1324-Count-Primes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
    int countPrimes(int n) {
        // write your code here

        vector<int> prime(n, 1);

        int cnt = 0;

        int end = sqrt(n) + 1;

        for (int i = 2; i < n; i++)
        {
            if (prime[i] != 1)
                continue;

            cnt++;
            for (int j = 2; i * j < n; j++)
            {
                prime[i * j] = 0;
            }
        }

        return cnt;
    }
};

int main()
{
    Solution solution;

    int result = solution.countPrimes(100);
}
