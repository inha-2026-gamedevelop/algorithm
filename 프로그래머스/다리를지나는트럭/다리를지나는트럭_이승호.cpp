#include <string>
#include <vector>
#include <queue>

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int onBridgeWeight = 0;
    size_t next = 0;
    queue<int> exitTime;
    queue<int> onBridge;

    bool isb = exitTime.empty();

    while (!exitTime.empty() || next < truck_weights.size())
    {
        time++;

        if (!exitTime.empty() && exitTime.front() == time)
        {
            exitTime.pop();
            onBridgeWeight -= onBridge.front();
            onBridge.pop();
        }

        if (next < truck_weights.size() && onBridgeWeight + truck_weights[next] <= weight)
        {
            onBridgeWeight += truck_weights[next];

            exitTime.push(time + bridge_length);
            onBridge.push(truck_weights[next]);
            next++;
        }
    }

    return time;
}