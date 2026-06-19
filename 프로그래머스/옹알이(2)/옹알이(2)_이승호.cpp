#include <string>
#include <vector>

using namespace std;

vector<string> arrs = { "aya", "ye", "woo", "ma" };

int solution(vector<string> babbling) {
    int answer = 0;
    int idx = -1; // 연속 방지하기 위해 

    for (auto str : babbling)
    {
        for (int i = 0; i < arrs.size(); ++i)
        {
            if (str.substr(0, arrs[i].size()) == arrs[i] && idx != i)
            {
                str.erase(0, arrs[i].size());

                idx = i;
                i = -1; // 다시 처음부터 돌리기
            }
        }
        if (str.empty()) answer++;
        idx = -1;
    }

    return answer;
}