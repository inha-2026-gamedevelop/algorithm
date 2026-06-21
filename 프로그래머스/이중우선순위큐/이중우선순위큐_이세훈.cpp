#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (string s : operations)
    {
        if (s[0] == 'D')
        {
            if (answer.size() == 0) continue;
            else if (s[2] == '-')
            {
                sort(answer.begin(), answer.end());
                answer.erase(answer.begin());
            }
            else
            {
                sort(answer.begin(), answer.end());
                answer.pop_back();
            }
        }
        else
        {
            answer.push_back(stoi(s.substr(2)));
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.size() == 0) return { 0,0 };
    else return { answer.back(), answer[0] };
}

/*
문제 내용에 따른 단순한 접근,
필요 기능 : 값 추가, 최대/최소 값 삭제
vector 와 sort 활용 시 해결 가능, 단 sort 는 삭제전 및 결과 계산 전 등 필요한 경우에만 수행
*/
