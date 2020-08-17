#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        // write your code here

        int num = n;

        string result = "";

        while (num > 0)
        {
            int d = num % 26;

            char c = 'A' + d;

            result = c + result;

            num = num / 26;
        }

        return result;
    }
};

int main() {
    Solution solution;

    string res = solution.convertToTitle(10);

    cout << res;

}