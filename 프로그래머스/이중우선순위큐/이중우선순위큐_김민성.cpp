#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations)
{
    multiset<int> ms;

    for (const string& op : operations)
    {
        char order = op[0];
        int  num   = stoi(op.substr(2));

        if (order == 'I')
        {
            ms.insert(num);
        }
        else
        {
            if (ms.empty()) continue;

            if (num == 1)
                ms.erase(prev(ms.end()));
            else
                ms.erase(ms.begin());
        }
    }

    if (ms.empty())
        return { 0, 0 };

    return { *ms.rbegin(), *ms.begin() };
}

// 멀티셋(균형 이진트리) 사용하면 
// 삽입 삭제 O(log n) 최댓값 최소값 접근 O(1) / O(n log n)
// 멀티셋 자체가 항상 정렬된 상태 유지해서 편함


// 예전에 풀었던 방식
// 삽입이 O(n log n) / 최악의 경우 O(n^2 log n)
// 삽입 할때마다 매번 전체배열 다시 정렬
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// vector<int> solution(vector<string> operations) 
// {
//     vector<int> answer = { 0,0 };
//     vector<int> v;

//     for (auto& s : operations) 
//     {
//         string order = s.substr(0, 1);
//         int num = stoi(s.substr(2));

//         if (order == "I") 
//         {
//             v.push_back(num);
//             sort(v.begin(), v.end(), greater<>());
//         }
//         else {
//             if (v.size() == 0) continue;

//             (num == -1) ? v.erase(v.end() - 1) : v.erase(v.begin());
//         }
//     }

//     if (!v.empty()) 
//     {
//         answer.clear();
//         answer = { v[0], v[v.size() - 1] };
//     }

//     return answer;
// }
