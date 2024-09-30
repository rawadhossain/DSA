#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

string frequencySort(string str)
{
    string output = "";

    unordered_map<char, int> map;
    priority_queue<pair<int, char>> pq;

    for (auto ch : str)
        map[ch]++;

    for (auto it : map)
        pq.push({it.second, it.first});

    while (!pq.empty())
    {
        for (int i = 0; i < pq.top().first; i++)
        {
            output += pq.top().second;
        }

        pq.pop();
    }

    return output;
}