// 146-LRU Cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
public:

    int cap;
    list<pair<int, int>> l;

    unordered_map<int, list<pair<int, int>>::iterator> m;

    LRUCache(int capacity) {

        cap = capacity;
    }

    int get(int key) {

        if (m.count(key) == 0)
            return -1;

        auto it = m[key];

        l.splice(l.begin(), l, it);

        return it->second;

    }

    void put(int key, int value) {

        if (m.count(key) != 0)
        {
            l.erase(m[key]);
        }

        l.insert(l.begin(), { key, value });
        m[key] = l.begin();


        //check capacity
        if (m.size() > cap)
        {
            int k = l.back().first;
            m.erase(k);
            l.pop_back();
        }
    }
};



int main()
{
    LRUCache lRUCache(2);

    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4}

}