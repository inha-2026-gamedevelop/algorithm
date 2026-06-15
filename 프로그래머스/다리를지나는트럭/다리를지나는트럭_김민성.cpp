#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<int> bridge;
    for (int i = 0; i < bridge_length; ++i) bridge.push(0);

    int curWeight = 0;
    int time = 0;
    int idx = 0;
    int n = static_cast<int>(truck_weights.size());

    while (idx < n)
    {
        ++time;

        curWeight -= bridge.front();
        bridge.pop();

        if ((curWeight + truck_weights[idx]) <= weight)
        {
            curWeight += truck_weights[idx];
            bridge.push(truck_weights[idx]);
            ++idx;
        }
        else bridge.push(0);
    }
    time += bridge_length;

    return time;
}