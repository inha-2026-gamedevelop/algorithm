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

// 큐
// 다리를 큐로 표현한다.(bridge)
// 크기는 항상 bridge_length로 유지한다.
// 매 초마다 맨 앞 칸이 빠져나간다(다리를 다 건넌 트럭) -> curWeight에서 빠져나간 트럭의 무게를 빼준다.
// 다음 트럭이 탈 수 있으면 pugh 못타면 0 push

// bridge_length=2, weight=10, trucks=[7,4,5,6], return=8 인 경우(입출력 예 1번)
// 1. time=1: bridge=[0,7], curWeight=7
// 2. time=2: bridge=[7,0], curWeight=7 (4는 못탐, 7+4가 10보다 크기 때문)
// 3. time=3: bridge=[0,4], curWeight=4 (7이 빠져나감, 4는 탑승)
// 4. time=4: bridge=[4,5], curWeight=9 (5는 탑승)
// 5. time=5: bridge=[5,0], curWeight=5 (6은 못탐)
// 6. time=6: bridge=[0,6], curWeight=6 idx == n, 마지막 트럽 탑승
// 여기까지 하면 모든 트럭이 탑승되는데 아직 다리를 다 건너지는 않았다. 
// 마지막 다리를 완전히 건너려면 bridge_length 만큼의 시간이 더 필요하다. 따라서 time += bridge_length 해준다. (time(6) + bridge_length(2) = 8)
// 그래서 return이 8이다
