#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    unordered_map<int, vector<int>> graph;

    for (auto vertex : edge) {
        graph[vertex[0]].push_back(vertex[1]);
        graph[vertex[1]].push_back(vertex[0]);
    }

    unordered_map<int, int> dist;
    queue<int> dfsQueue;
    dfsQueue.push(1);
    dist[1] = 0;
    int far = 0;

    while (!dfsQueue.empty()) {
        int index = dfsQueue.front();
        dfsQueue.pop();

        for (auto to : graph[index]) {
            if (dist.find(to) == dist.end()) {
                dist[to] = dist[index] + 1;
                dfsQueue.push(to);

                far = dist[to];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == far) answer++;
    }

    return answer;
}

