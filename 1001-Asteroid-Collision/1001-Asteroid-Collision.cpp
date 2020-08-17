// 1001-Asteroid-Collision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param asteroids: a list of integers
     * @return: return a list of integers
     */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // write your code here

        stack<int> s;

        vector<int> result;

        for (int i = 0; i < asteroids.size(); i++)
        {

            int current = asteroids[i];

            if (current > 0)
            {
                s.push(current);
                result.push_back(current);
            }
            // there is collision
            else if (current < 0 && s.empty() == false)
            {
                int prev = s.top();

                if (prev < abs(current))
                {
                    s.pop();
                    i--;
                    result.pop_back();
                }
                else if (prev == abs(current))
                {
                    s.pop();
                    result.pop_back();
                }
                else
                {
                    continue;
                }
            }
            else if (current < 0 && s.empty() == true)
            {
                result.push_back(current);
            }
        }

        //while (s.empty() == false)
        //{
        //    result.push_back(s.top());
        //    s.pop();
        //}

        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> v1{ 5, 10, -5 };

    vector<int> v2{ 7,-1,2,-3,-6,-6,-6,4,10,2 };

    vector<int> res = solution.asteroidCollision(v2);

}
