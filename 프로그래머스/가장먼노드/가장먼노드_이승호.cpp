#include <string>
#include <vector>
#include <cstdint>
#include <queue>

using namespace std;

int dijkstra(int n, vector<vector<int>> v)
{
    vector<int> best(n + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    best[1] = 0;
    pq.push({0, 1}); // cost, node - pair ,  앞에꺼를 기준으로 정렬하기 때문에
    
    while(!pq.empty())
    {
        int currCost = pq.top().first;
        int currNode = pq.top().second;
        
        pq.pop();
        
        for (int i = 0; i < v[currNode].size(); ++i)
        {
            int nextCost = currCost + 1;
            
            if (nextCost >=  best[v[currNode][i]])
                continue;
            
            best[v[currNode][i]] = nextCost;
            pq.push({nextCost, v[currNode][i]});
        }
    }
    
     //가장 먼 거리의 값 구하고
    int max_dist = 0;
    for (int i = 1; i <= n; ++i) {
        if (best[i] != INT32_MAX) {
            max_dist = max(max_dist, best[i]);
        }
    }
    
     //가장 먼 거리에 있는 노드들 개수 구하기
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (best[i] == max_dist) {
            answer++;
        }
    }

    return answer;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> v(n + 1);
    
    for (int i = 0; i < edge.size(); ++i)
    {
        int node1 = edge[i][0];
        int node2 = edge[i][1];
        
        
         //양방향
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    
    answer = dijkstra(n, v);
    
    
    
    return answer;
}