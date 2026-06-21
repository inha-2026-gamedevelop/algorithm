#include <string>
#include <vector>

using namespace std;
vector<string> strings{ "aya", "ye", "woo", "ma" };

bool say(string& s, string& prev)
{
    for (auto str : strings)
    {
        if (s.substr(0, str.size()) == str)
        {
            if (str == prev) break;

            s.erase(0, str.size());
            prev = str;
            return true;
        }
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;


    for (auto b : babbling)
    {
        string prevstring = "";

        while (say(b, prevstring)) {}

        if (b == "") ++answer;
    }

    return answer;
}
