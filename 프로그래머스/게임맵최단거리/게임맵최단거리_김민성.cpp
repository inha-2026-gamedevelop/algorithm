#include <vector>
#include <queue>

using namespace std;

struct Position
{
    int r, c;
};

int solution(vector<vector<int>> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1)); // -1 = 미방문
    dist[0][0] = 1;

    int dr[4] = { 0, 0, 1, -1 }; // 동, 서, 남, 북
    int dc[4] = { 1, -1, 0, 0 };

    queue<Position> q;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        Position cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nr = cur.r + dr[dir];
            int nc = cur.c + dc[dir];

            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= m))
                continue;
            if (maps[nr][nc] == 0)
                continue;
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[cur.r][cur.c] + 1;
            q.push({ nr, nc });
        }
    }

    return dist[n - 1][m - 1];
}

// BFS
// 모든 이동 비용이 동일한 그래프에서는
// 출발점으로부터 가까운 칸 순서대로 퍼져나가는 BFS 가 항상 최단 거리를 보장함
// 예시 입출력 #1
// maps = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]
//
// 1) dist[0][0] = 1, 큐 = [(0,0)]
// 2) (0,0) 꺼냄 -> 갈 수 있는 이웃 칸들의 dist 를 2 로 채우고 큐에 넣음
// 3) 거리 2인 칸들을 차례로 꺼내며 -> 거리 3인 칸들 발견 -> 반복
// 4) (4,4) 에 처음 도달하는 순간의 dist 값이 답
// 5) 위 입력에서는 dist[4][4] = 11 -> return 11
