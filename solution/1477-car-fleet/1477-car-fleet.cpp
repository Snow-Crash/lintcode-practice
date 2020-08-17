// 1477-car-fleet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * @param target: the target
     * @param position: the initial position
     * @param speed: the speed
     * @return: How many car fleets will arrive at the destination
     */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Write your code here

        vector<pair<int, float>> cars;

        for (int i = 0; i != position.size(); i++)
        {
            cars.push_back({ position[i], (float)(target - position[i]) / speed[i] });
        }

        sort(cars.begin(), cars.end(), comp);

        float current_arrive_time = 0;
        int result = 0;

        for (int i = 0; i != cars.size(); i++)
        {
            if (cars[i].second <= current_arrive_time)
                continue;
            current_arrive_time = cars[i].second;
            result += 1;
        }

        return result;
    }

    static bool comp(pair<int, float>& car1, pair<int, float>& car2)
    {
        return car1.first > car2.first;
    }

};

int main()
{
    int target = 17;
    vector<int> position { 8,12,16,11,7 };
    vector<int> speed { 6,9,10,9,7 };

    Solution solution;
    int result = solution.carFleet(target, position, speed);
}
