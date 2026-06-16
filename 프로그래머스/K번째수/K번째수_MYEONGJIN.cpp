#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool com(string& s1, string& s2, int n)
{
    if (s1[n] == s2[n])
        {
            return s1 > s2;
        }
    return s1[n] > s2[n];
}

vector<string> solution(vector<string> strings, int n)
{
    for (int i = strings.size() - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (com(strings[j], strings[j + 1], n))
            {
                string temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
    return strings;
}
