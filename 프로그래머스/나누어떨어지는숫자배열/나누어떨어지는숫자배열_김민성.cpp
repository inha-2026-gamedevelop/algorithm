#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
	vector<int> answer;

	sort(arr.begin(), arr.end());

    for (auto i : arr) {
		if (0 == (i % divisor)) 
		{
			printf("%d ", i);
			answer.push_back(i);
		}
	}
	return answer.empty() ? vector<int>(1, -1) : answer;
}
