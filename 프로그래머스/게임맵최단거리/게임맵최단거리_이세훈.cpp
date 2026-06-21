#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    //priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    queue<pair<int, pair<int, int>>> pq;
    maps[0][0] = 0;
    pq.push({ 1, {0, 0} });

    while (!pq.empty())
    {
        auto [cost, pos] = pq.front();
        if (pos.first == n && pos.second == m) return cost;

        pq.pop();
        if (pos.first > 0 && maps[pos.first - 1][pos.second] != 0)
        {
            maps[pos.first - 1][pos.second] = 0;
            pq.push({ cost + 1, {pos.first - 1, pos.second} });
        }
        if (pos.first < n && maps[pos.first + 1][pos.second] != 0)
        {
            maps[pos.first + 1][pos.second] = 0;
            pq.push({ cost + 1, {pos.first + 1, pos.second} });
        }
        if (pos.second > 0 && maps[pos.first][pos.second - 1] != 0)
        {
            maps[pos.first][pos.second - 1] = 0;
            pq.push({ cost + 1, {pos.first, pos.second - 1} });
        }
        if (pos.second < m && maps[pos.first][pos.second + 1] != 0)
        {
            maps[pos.first][pos.second + 1] = 0;
            pq.push({ cost + 1, {pos.first, pos.second + 1} });
        }
    }

    return -1;
}

/*
1. 탐색을 위한 dfs vs bfs
최단 경로 탐색 시 bfs 가 더 유리한 경우가 많아 bfs 선택

2. 우선순위 큐에서 일반 큐로 변경
가까운 곳부터 먼곳 순서의 탐색이 필요해 우선순위 큐를 사용했으나 효율성 체크 실패
고민 결과 큐에 특성과 추가되는 순서를 고려하면 우선순위 큐를 사용하지 않아도 문제가 없음을 확인하고 일반 큐로 변경, 테스트 성공
*/
