// 1116-Exclusive-Time-of-Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param n: a integer
     * @param logs: a list of integers
     * @return: return a list of integers
     */
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // write your code here

        vector<int> count(n, 0);

        stack<int> s;

        int last_t = 0;
        int current_id = -1;

        for (int i = 0; i != logs.size(); i++)
        {
            string line = logs[i];
            vector<string> split;

            size_t start = 0;
            size_t end = 0;
            end = line.find(':');

            while (end < string::npos)
            {
                split.push_back(line.substr(start, end - start));
                start = end + 1;
                end = line.find(':', start);
            }
            split.push_back(line.substr(start, end - start));


            int new_id = stoi(split[0]);
            int stamp = stoi(split[2]);
            string op = split[1];

            if (op == "start")
            {
                if (s.empty() == false)
                    count[s.top()] = count[s.top()] + stamp - last_t;

                s.push(new_id);

                last_t = stamp;
            }
            else
            {
                count[s.top()] = count[s.top()] + stamp - last_t + 1;
                s.pop();
                last_t = stamp + 1;
            }
        }

        return count;

    }
};

int main()
{
    Solution solution;

    vector<string> l1{ "0:start:0","1:start:2","1:end:5","0:end:6" };

    vector<string> l2{ "0:start:0","1:start:4","2:start:6","3:start:11","4:start:14","5:start:17","6:start:22","7:start:25","8:start:27","9:start:31","8:start:38","8:end:43","9:start:44","9:end:49","9:end:52","8:end:54","7:end:55","6:end:60","5:end:65","0:start:68","0:end:72","4:end:75","3:end:77","2:end:81","1:end:85","0:end:88" };

    vector<int> res = solution.exclusiveTime(2, l1);

    std::cout << "Hello World!\n";
}