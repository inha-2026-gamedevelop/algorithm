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
                if (far != dist[index] + 1) answer = 0;
                dist[to] = dist[index] + 1;
                dfsQueue.push(to);
                far = dist[to];
                ++answer;
            }
        }
    }
    /*
    for(int i=1; i<=n; i++){
        if(dist[i] == far) answer++;
    }
    */
    return answer;
}

/*
graph 를 통해 각 노드마다 연결 된 노드를 저장
이후 다익스르타 알고리즘을 적용해 거리 확인
하단 for 문 체크를 통해 가장 먼 노드의 개수를 직접 샐 수 있지만,
큐에 push 할 때, 체크를 통해 정답을 구할 수 있음 -> 전체 순회 1회가 줄어듬
큐에 push 할 때, answer 를 올리고
if (far != dist[index] + 1) 를 통해  거리가 바뀐 경우 answer 를 0으로 초기화 하는 방식 사용
*/
