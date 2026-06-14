#include <string>
#include <vector>

using namespace std;

void swap(vector<string>& strings, int i)
{
    string temp = strings[i + 1];
    strings[i + 1] = strings[i];
    strings[i] = temp;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    for (int i = 0; i < strings.size() - 1; ++i)
    {
        for (int j = 0; j < strings.size() - 1 - i; ++j)
        {
            if (strings[j][n] > strings[j + 1][n])
            {
                swap(strings, j);
            }
            else if (strings[j][n] == strings[j + 1][n] && strings[j] > strings[j + 1])
            {
                swap(strings, j);
            }
        }
    }

    return strings;
}