#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    if (arr.empty())
    {
        return answer;
    }
    for (auto c : arr)
    {
        if (answer.empty() || answer.back() != c)
        {
            answer.push_back(c);
        }
        else
        {
            continue;
        }
    }

    return answer;
}
