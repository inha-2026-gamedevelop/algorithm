#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int totalweight = 0;
    int i = 0;
    queue<int> q;

    while (1) {
        if (i == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }

        if (q.size() == bridge_length)
        {
            totalweight -= q.front();
            q.pop();
        }

        if (weight - totalweight >= truck_weights[i])
        {
            q.push(truck_weights[i]);
            totalweight += truck_weights[i];
            ++i;
        }
        else q.push(0);

        ++answer;
    }

    return answer;
}