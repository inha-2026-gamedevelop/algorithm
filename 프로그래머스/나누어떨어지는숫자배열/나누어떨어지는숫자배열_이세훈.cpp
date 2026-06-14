#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

    for (auto num : arr)
    {
        if (num % divisor == 0)
        {
            for (int i = 0; i <= answer.size(); ++i)
            {
                if (i == answer.size())
                {
                    answer.push_back(num);
                    break;
                }
                if (answer[i] < num) continue;
                else
                {
                    answer.insert(answer.begin() + i, num);
                    break;
                }
            }
        }
    }

    if (answer.size() == 0) return { -1 };
    else return answer;
}