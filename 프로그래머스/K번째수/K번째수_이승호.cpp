#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 아직 퀵정렬 사용 x

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
        vector<int> answer;

    vector<int> arr;

    for (auto command : commands)
    {
        arr.clear();

        for (int i = command[0]; i <= command[1]; i++)
        {
            arr.push_back(array[i - 1]);
        }

        sort(arr.begin(), arr.end());
        answer.push_back(arr[command[2] - 1]);
    }

    return answer;
}