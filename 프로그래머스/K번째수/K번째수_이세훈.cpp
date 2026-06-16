#include <string>
#include <vector>

using namespace std;

void quicksort(vector<int>& arr, int start, int end)
{
    if (start >= end) return;

    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (i <= end && arr[i] <= arr[pivot]) ++i;
        while (j > start && arr[j] >= arr[pivot]) --j;

        int temp;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
    }
    quicksort(arr, start, j - 1);
    quicksort(arr, j + 1, end);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto c : commands)
    {
        vector<int> slice(array.begin() + c[0] - 1, array.begin() + c[1]);

        quicksort(slice, 0, slice.size() - 1);

        answer.push_back(slice[c[2] - 1]);
    }

    return answer;
}
