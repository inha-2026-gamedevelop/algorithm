#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int m;

bool cmp(const string& a, const string& b) {
    return a[m] != b[m] ? a[m] < b[m] : a < b;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    m = n;
    sort(strings.begin(), strings.end(), cmp);

    return answer = strings;
}
