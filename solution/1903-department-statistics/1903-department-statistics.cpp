// 1903-department-statistics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @param employees: information of the employees
     * @param friendships: the friendships of employees
     * @return: return the statistics
     */
    vector<string> departmentStatistics(vector<string>& employees, vector<string>& friendships) {
        // write your code here.

        unordered_map<string, string> id_department_map;
        unordered_map<string, int> friendship_counter;
        unordered_map<string, int> department_employee_counter;
        string delim = ", ";

        for (int i = 0; i != employees.size(); i++)
        {
            vector<string> splitted = split(employees[i], delim);
            id_department_map[splitted[0]] = splitted[2];

            if (department_employee_counter.find(splitted[2]) == department_employee_counter.end())
                department_employee_counter[splitted[2]] = 1;
            else
                department_employee_counter[splitted[2]] += 1;

            if (friendship_counter.find(splitted[2]) == friendship_counter.end())
            {
                friendship_counter[splitted[2]] = 0;
            }

        }

        for (int i = 0; i != friendships.size(); i++)
        {
            vector<string> splitted = split(friendships[i], delim);

            string from_id = splitted[0];
            string to_id = splitted[1];

            string from_department = id_department_map[from_id];
            string to_department = id_department_map[to_id];

            if (from_department.compare(to_department) != 0)
            {
                friendship_counter[from_department] += 1;

                friendship_counter[to_department] += 1;
            }
        }

        vector<string> result;

        for (auto it = department_employee_counter.begin(); it != department_employee_counter.end(); it++)
        {
            string department = it->first;
            int employee_count = it->second;

            int friend_count = friendship_counter[department];

            string str = department + ": " + to_string(friend_count) + " of " + to_string(employee_count);

            result.push_back(str);
        }

        return result;

    }

    vector<string> split(string& str, string& delim)
    {
        size_t start = 0;
        size_t end = str.find(delim);

        vector<string> splitted_string;

        while (end != std::string::npos)
        {
            splitted_string.push_back(str.substr(start, end - start));
            start = end + delim.length();
            end = str.find(delim, start);
        }

        splitted_string.push_back(str.substr(start, end));

        return splitted_string;
    }

};

int main()
{

    vector<string> input = { "0, Barnett, HR","1, Andre, Engineer","2, Antonio, Law","3, Andrew, HR",
        "4, Amos, Advertising","5, Barlow, Advertising","6, Antony, Business","7, Andy, Business",
        "8, Angelo, Purchase","9, Ansel, Law","10, Antoine, Finance","11, Augus, Law","12, Barret, Finance",
        "13, Baron, Finance","14, Bard, Law" };
    vector<string> friendship = { "5, 2","6, 11","3, 9","7, 2","4, 10","9, 8","6, 2","14, 6","1, 8","13, 2" };

    Solution solution;

    vector<string> result = solution.departmentStatistics(input, friendship);
    
    std::cout << "Hello World!\n";
}
