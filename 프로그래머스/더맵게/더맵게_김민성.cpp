#include <vector>
#include <queue>

using namespace std;

// 시간복잡도 : O(N)
int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    int count = 0;

    while (pq.top() < K)
    {
        if (pq.size() < 2) return -1;

        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        ++count;
    }

    return count;
}

// 기존 방식
// 시간복잡도 : O(log(N))
/*int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i : scoville)
    {
        pq.push(i);
    }

    int count = 0, index = 0;
    while(true)
    {
        if(pq.top() < K)
        {
            int temp = pq.top();
            pq.pop();
            if(pq.empty()) return -1;

            pq.push(temp + pq.top() * 2);
            pq.pop();
            ++count;
        }
        else
        {
            pq.pop();
            if(pq.empty()) break;
        }
    }

    return count;
}*/
