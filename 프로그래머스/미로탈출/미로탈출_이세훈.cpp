#include <string>
#include <vector>
#include <queue>

using namespace std;

int TimeToTarget(pair<int, int>& start, char target1, char target2, vector<string>& maps)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> temp_q;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    q.push(start);
    visited[start.first][start.second] = true;

    int time = 0;
    int time_to_t1 = 0;
    int time_to_t2 = 0;

    while (!q.empty())
    {
        pair<int, int> pos = q.front();

        if (maps[pos.first][pos.second] == target1)
        {
            if (time_to_t2 != 0) return time_to_t2 + time;
            time_to_t1 = time;
        }
        if (maps[pos.first][pos.second] == target2)
        {
            if (time_to_t1 != 0) return time_to_t1 + time;
            time_to_t2 = time;
        }

        q.pop();

        if (pos.first > 0 &&
            maps[pos.first - 1][pos.second] != 'X' &&
            !visited[pos.first - 1][pos.second])
        {
            visited[pos.first - 1][pos.second] = true;
            temp_q.push({ pos.first - 1, pos.second });
        }

        if (pos.first < maps.size() - 1 &&
            maps[pos.first + 1][pos.second] != 'X' &&
            !visited[pos.first + 1][pos.second])
        {
            visited[pos.first + 1][pos.second] = true;
            temp_q.push({ pos.first + 1, pos.second });
        }

        if (pos.second > 0 &&
            maps[pos.first][pos.second - 1] != 'X' &&
            !visited[pos.first][pos.second - 1])
        {
            visited[pos.first][pos.second - 1] = true;
            temp_q.push({ pos.first, pos.second - 1 });
        }

        if (pos.second < maps[pos.first].size() - 1 &&
            maps[pos.first][pos.second + 1] != 'X' &&
            !visited[pos.first][pos.second + 1])
        {
            visited[pos.first][pos.second + 1] = true;
            temp_q.push({ pos.first, pos.second + 1 });
        }

        if (q.empty())
        {
            if (temp_q.empty()) return -1;
            else
            {
                while (!temp_q.empty())
                {
                    q.push(temp_q.front());
                    temp_q.pop();
                }
                ++time;
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> lever;
    bool findStart = false;
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[i].size(); ++j)
        {
            if (maps[i][j] == 'L') {
                lever = { i, j };
                findStart = true;
                break;
            }
        }
        if (findStart) break;
    }

    return TimeToTarget(lever, 'S', 'E', maps);
}

/*
가장 먼저 떠오르는 방식 : 시작 -> 레버, 레버 -> 끝 시간 각각 계산 후 더하기
처음 테스트 결과 시간초과 발생 -> 고민 하다 처음 시작 위치를 레버로 설정해 레버 -> 시작, 레버 -> 끝 을 한번에 구해 더하기로 결정
<시간 초과는 큐에 푸쉬할 때 제외할 조건을 잘못 걸어서 생김>
큐에 cost 를 저장할 수도 있지만, 별도의 큐를 활용해 같은 cost 의 순회를 체크하는 방식도 활용 가능
*/
