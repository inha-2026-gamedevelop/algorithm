#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 버블정렬은 아직 못함

vector<string> solution(vector<string> strings, int n) {
        sort(strings.begin(), strings.end(), [n](string str1, string str2)
        {
            return str1[n] == str2[n] ? str1 < str2 : str1[n] < str2[n];
        });
    return strings;
}